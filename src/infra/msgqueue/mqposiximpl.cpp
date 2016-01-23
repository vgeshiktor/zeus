/**
 ** File Name : mqposiximpl.cpp
 ** Purpose :                                                
 ** Creation Date : Nov 30, 2015
 ** Last Modified : Sat 23 Jan 2016 02:11:05 AM IST
 ** Created By : vadim
 **/

#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include "mqposiximpl.h"

namespace infra 
{
	namespace msgqueue 
	{
		mqposiximpl::mqposiximpl() : m_mqdes(-1)
		{
		}

		mqposiximpl::~mqposiximpl()
		{
		}

		int mqposiximpl::open(const char* name, bool isOwner)
		{
			if(valid())
				return m_mqdes;

			if(!name || !name[0])
				return -1;

			if(!isValidQname(name))
				return -1;

			buildQname(name);

			if(isOwner)
			{
				// TODO: read values from configuration
				mq_attr attr = mq_attr();
				attr.mq_maxmsg = 2000;
				attr.mq_msgsize = 1000;

				m_mqdes = mq_open(m_qname.c_str(), O_RDWR | O_CREAT, S_IRWXU, &attr);

				{
					// TODO: debug only, should be removed
					mq_attr attr;
					if(getattr(&attr))
						printf("maxmsg=%ld, msgsize=%ld\n", attr.mq_maxmsg, attr.mq_msgsize);
				}

				//m_mqdes = mq_open(m_qname.c_str(), O_RDONLY | O_CREAT, S_IRWXU, &attr);
			}
			else
				m_mqdes = mq_open(m_qname.c_str(), O_WRONLY);

			return m_mqdes;
		}

		int mqposiximpl::close()
		{
			if(!valid())
				return -1;

			int res = mq_close(m_mqdes);
			m_mqdes = -1;

			return res;
		}

		int mqposiximpl::send(const char* msg, size_t len, unsigned prio)
		{
			if(!valid())
				return -1;

			return mq_send(m_mqdes, msg, len, prio);
		}

		int mqposiximpl::receive(char *msg, size_t len, unsigned* prio)
		{
			if(!valid())
				return -1;

			int res = mq_receive(m_mqdes, msg, len, prio);
			if(res)
				msg[res] = 0;

			return res;
		}

		int mqposiximpl::timedsend(const char* msg, size_t len, unsigned prio, 
				const struct timespec *abs_timeout)
		{
			if(!valid())
				return -1;

			return mq_timedsend(m_mqdes, msg, len, prio, abs_timeout);
		}

		int mqposiximpl::timedreceive(char* msg, size_t len, unsigned* prio,
				const struct timespec *abs_timeout)
		{
			if(!valid())
				return -1;

			return mq_timedreceive(m_mqdes, msg, len, prio, abs_timeout);
		}

		int mqposiximpl::notify(const struct sigevent* sevp)
		{
			if(!valid())
				return -1;

			return mq_notify(m_mqdes, sevp);
		}

		int mqposiximpl::getattr(struct mq_attr* attr)
		{
			if(!valid())
				return -1;

			return mq_getattr(m_mqdes, attr);
		}

		int mqposiximpl::setattr(struct mq_attr* newattr, struct mq_attr* oldattr)
		{
			if(valid())
				return -1;

			return mq_setattr(m_mqdes, newattr, oldattr);
		}

		int mqposiximpl::unlink()
		{
			if(m_qname.empty())
				return false;

			return mq_unlink(m_qname.c_str());
		}

		bool mqposiximpl::valid() const noexcept
		{
			return -1 != m_mqdes;
		}

		bool mqposiximpl::isValidQname(const char* name)
		{
			if( !(name && name[0] && '/' != name[0]) )
				return false;

			return true;
		}

		void mqposiximpl::buildQname(const char* name)
		{
			std::stringstream ss;
			ss << '/' << name;
			m_qname = ss.str();
		}
	}
}

#if defined(TEST)
int main(int argc, char* argv[])
{
#endif /* defined(TEST) */
#if defined(SERVER) || defined(CLIENT)
	char* msg = 2 == argc ? argv[1] : (char*)"test message";
#endif /* defined(SERVER) || defined(CLIENT) */

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
#if defined(TEST)
	return 0;
}
#endif /* defined(TEST) */

