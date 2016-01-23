/**
 ** File Name : msgqueueifs.h
 ** Purpose :                                                
 ** Creation Date : Nov 30, 2015
 ** Last Modified : Fri 22 Jan 2016 08:55:00 PM IST
 ** Created By : vadim
 **/

#ifndef __MESSAGE_QUEUE_IFS__H_
#define __MESSAGE_QUEUE_IFS__H_

#include <mqueue.h>
#include <time.h>

namespace infra
{
	namespace msgqueue
	{
		class msgqueueifs
		{
			public:
				virtual int open(const char* name, bool isOwner) = 0;
				virtual int close() = 0;
				virtual int send(const char* msg, size_t len, unsigned prio) = 0;
				virtual int receive(char *msg, size_t len, unsigned* prio) = 0;
				virtual int timedsend(const char* msg, size_t len, unsigned prio, 
						const struct timespec *abs_timeout) = 0;
				virtual int timedreceive(char *msg, size_t len, unsigned* prio, 
						const struct timespec *abs_timeout) = 0;
				virtual int notify(const struct sigevent* sevp) = 0;
				virtual int getattr(struct mq_attr* attr) = 0;
				virtual int setattr(struct mq_attr* newattr, struct mq_attr* oldattr) = 0;
				virtual int unlink() = 0;
				virtual bool valid() const noexcept = 0;
		};
	}
}

#endif //  __MESSAGE_QUEUE_IFS__H_
