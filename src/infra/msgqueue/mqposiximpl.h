/**
 ** File Name : mqposiximpl.h
 ** Purpose :                                                
 ** Creation Date : Nov 30, 2015
 ** Last Modified : Fri 22 Jan 2016 08:55:57 PM IST
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

				int open(const char* name, bool isOwner);
				int close();
				int send(const char* msg, size_t len, unsigned prio);
				int receive(char *msg, size_t len, unsigned* prio);
				int timedsend(const char* msg, size_t len, unsigned prio, const struct timespec *abs_timeout);
				int timedreceive(char *msg, size_t len, unsigned* prio, const struct timespec *abs_timeout);
				int notify(const struct sigevent* sevp);
				int getattr(struct mq_attr* attr);
				int setattr(struct mq_attr* newattr, struct mq_attr* oldattr);
				int unlink();
				bool valid() const noexcept;

			private:
				bool isValidQname(const char* name);
				void buildQname(const char* name);

			private:
				std::string m_qname;
				mqd_t m_mqdes;
		};
	}
}

#endif // __MQ_POSIX_IMPL__H_
