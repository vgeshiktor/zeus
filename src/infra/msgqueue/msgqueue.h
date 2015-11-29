/**
 ** File Name : msgqueue.h
 ** Purpose :                                                
 ** Creation Date : Nov 12, 2015
 ** Last Modified : Fri 13 Nov 2015 01:36:28 PM IST
 ** Created By : vadim
 **/

#include <mqueue.h>
#include <time.h>

namespace infra
{
	class msgqueue
	{
		public:
			explicit msgqueue(const char* name);
			~msgqueue();

			msgqueue(msgqueue const&) = delete;
			msgqueue& operator=(msgqueue const&) = delete;

			bool open(bool isOwner);
			bool close();
			bool send(const char* msg, size_t len, unsigned prio);
			bool receive(char *msg, size_t len, unsigned* prio);
			bool timedsend(const char* msg, size_t len, unsigned prio, const struct timespec *abs_timeout);
			bool timedreceive(char *msg, size_t len, unsigned* prio, const struct timespec *abs_timeout);
			bool notify(const struct sigevent* sevp);
			bool getattr(struct mq_attr* attr);
			bool setattr(struct mq_attr* newattr, struct mq_attr* oldattr);
			bool unlink();

			int getlasterror();

		private:
			bool isValidQname();

		private:
			const char* m_qname;
			mqd_t m_mqdes;
			int m_errno;
	};
}
