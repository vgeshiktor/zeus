/**
 ** File Name : msgqueue.cpp
 ** Purpose :                                                
 ** Creation Date : Nov 12, 2015
 ** Last Modified : Sun 15 Nov 2015 01:33:59 PM IST
 ** Created By : vadim
 **/

#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "msgqueue.h"

namespace infra 
{
	msgqueue::msgqueue(const char* name) : m_qname(strdup(name)), m_mqdes(-1), m_errno(0)
	{
	}

	msgqueue::~msgqueue()
	{
		free((void*)m_qname);
	}

	bool msgqueue::open(bool isOwner)
	{
		if(-1 != m_mqdes)
		{
			m_errno = EACCES;
			return true;
		}

		if(!isValidQname())
		{
			m_errno = ENOENT;
			return false;
		}

		if(isOwner)
		{
			mq_attr attr = {0};
			attr.mq_maxmsg = 2000;
			attr.mq_msgsize = 1000;

			m_mqdes = mq_open(m_qname, O_RDONLY | O_CREAT, S_IRWXU, NULL /* &attr */);
		}
		else
			m_mqdes = mq_open(m_qname, O_WRONLY);

		m_errno = errno;

		return -1 != m_mqdes;
	}

	bool msgqueue::close()
	{
		if(-1 == m_mqdes)
		{
			m_errno = EBADF;
			return false;
		}

		int res = mq_close(m_mqdes);
		m_errno = errno;
		m_mqdes = -1;

		return -1 != res;
	}

	bool msgqueue::send(const char* msg, size_t len, unsigned prio)
	{
		if(-1 == m_mqdes)
		{
			m_errno = EBADF;
			return false;
		}

		int res = mq_send(m_mqdes, msg, len, prio);
		m_errno = errno;

		return -1 != res;
	}

	bool msgqueue::receive(char *msg, size_t len, unsigned* prio)
	{
		if(-1 == m_mqdes)
		{
			m_errno = EBADF;
			return false;
		}

		int res = mq_receive(m_mqdes, msg, len, prio);
		m_errno = errno;

		return -1 != res;
	}

	bool msgqueue::timedsend(const char* msg, size_t len, unsigned prio, 
			const struct timespec *abs_timeout)
	{
		if(-1 == m_mqdes)
		{
			m_errno = EBADF;
			return false;
		}

		int res = mq_timedsend(m_mqdes, msg, len, prio, abs_timeout);
		m_errno = errno;

		return -1 != res;
	}

	bool msgqueue::timedreceive(char* msg, size_t len, unsigned* prio,
			const struct timespec *abs_timeout)
	{
		if(-1 == m_mqdes)
		{
			m_errno = EBADF;
			return false;
		}

		int res = mq_timedreceive(m_mqdes, msg, len, prio, abs_timeout);
		m_errno = errno;

		return -1 != res;
	}

	bool msgqueue::notify(const struct sigevent* sevp)
	{
		if(-1 == m_mqdes)
		{
			m_errno = EBADF;
			return false;
		}

		int res = mq_notify(m_mqdes, sevp);
		m_errno = errno;

		return -1 != res;
	}

	bool msgqueue::getattr(struct mq_attr* attr)
	{
		if(-1 == m_mqdes)
		{
			m_errno = EBADF;
			return false;
		}

		int res = mq_getattr(m_mqdes, attr);
		m_errno = errno;

		return -1 != res;
	}

	bool msgqueue::setattr(struct mq_attr* newattr, struct mq_attr* oldattr)
	{
		if(-1 == m_mqdes)
		{
			m_errno = EBADF;
			return false;
		}

		int res = mq_setattr(m_mqdes, newattr, oldattr);
		m_errno = errno;

		return -1 != res;
	}

	bool msgqueue::unlink()
	{
		if(!isValidQname())
		{
			m_errno = EACCES;
			return false;
		}

		int res = mq_unlink(m_qname);
		m_errno = errno;

		return -1 != res;
	}

	int msgqueue::getlasterror()
	{
		return m_errno;
	}

	bool msgqueue::isValidQname()
	{
		if(!m_qname || '/' != m_qname[0])
			return false;

		return true;
	}
}

int main(int argc, char* argv[])
{
	char* msg = 2 == argc ? argv[1] : (char*)"test message";

#ifdef SERVER
	printf("starting server, mq=\"/test\"\n");
	infra::msgqueue mqserver("/test");
	if(!mqserver.open(true))
	{
		printf("failed to open server mq \"/test\" error code:%d\n",
				mqserver.getlasterror());
		return -1;
	}
#endif /* SERVER */ 

#ifdef CLIENT
	printf("starting client, connecting to server mq=\"/test\"\n");
	infra::msgqueue mqclient("/test");
	if(!mqclient.open(false))
	{
		printf("failed to open client mq \"/test\" error code:%d\n",
				mqclient.getlasterror());
		return -1;
	}

	mq_attr attr = {0};
	if(!mqclient.getattr(&attr))
	{
		printf("failed to get queue attributes\n");
		return -1;
	}

	printf("msg_max = %ld\nmsg_size = %ld\n", attr.mq_maxmsg,
			attr.mq_msgsize);

# if defined(CLIENT) && defined(MULTIPLE)
	printf("will continuously send messages, use Ctrl-c to stop\n");
	while(1)
# endif /* CLIENT && MULTIPLE */
	{
		if(!mqclient.send(msg, strlen(msg), 0))
		{
			printf("failed to send message to server, error code:%d\n",
					mqclient.getlasterror());
			return -1;
		}
		else 
			printf("sent %s successfully\n", msg);
	}
#endif /* CLIENT */

#ifdef SERVER
# if defined(SERVER) && defined(MULTIPLE)
	printf("will continuously receive messages, use Ctrl-c to stop\n");
	while(1)
# endif /* SERVER && MULTIPLE */
	{
		unsigned prio;
		char mymsg[8192] = {0};
		if(mqserver.receive(mymsg, 8192, &prio))
		{
			if(!mymsg || !mymsg[0])
			{
				printf("failed to receive message from client, error_code:%d\n",
						mqserver.getlasterror());
				return -1;
			}
			else
			{
				//if(!strcmp(mymsg, msg))
				printf("received %s\n", mymsg);
				//else
				//{
				//	printf("message is not the same:\n"
				//			"source msg was: %s\n"
				//			"received msg was: %s\n", msg, mymsg);
				//	return -1;
				//}
			}
		}
		else
		{
			printf("failed to receive message from client, error code:%d\n",
					mqserver.getlasterror());
			return -1;
		}
	}
#endif /* SERVER */

	return 0;
}

