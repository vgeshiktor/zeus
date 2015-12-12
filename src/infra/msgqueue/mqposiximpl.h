/**
 ** File Name : mqposiximpl.h
 ** Purpose :                                                
 ** Creation Date : Nov 30, 2015
 ** Last Modified : Fri 04 Dec 2015 06:26:30 PM IST
 ** Created By : vadim
 **/

#ifndef __MQ_POSIX_IMPL__H_
#define __MQ_POSIX_IMPL__H_

#include <mqueue.h>
#include <time.h>
#include <string>
#include "msgqueueifs.h"

namespace infra
{
	namespace msgqueue
	{
		class mqposiximpl : public msgqueueifs
		{
			public:
				mqposiximpl();
				virtual ~mqposiximpl();

				mqposiximpl(mqposiximpl const&) = delete;
				mqposiximpl& operator=(mqposiximpl const&) = delete;

				bool open(const char* name, bool isOwner);
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
				bool isValidQname(const char* name);
				void buildQname(const char* name);

			private:
				std::string m_qname;
				mqd_t m_mqdes;
				int m_errno;
		};
	}
}

#endif // __MQ_POSIX_IMPL__H_
