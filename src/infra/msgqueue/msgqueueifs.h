/**
 ** File Name : msgqueueifs.h
 ** Purpose :                                                
 ** Creation Date : Nov 30, 2015
 ** Last Modified : Fri 04 Dec 2015 06:33:40 PM IST
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
				virtual bool open(const char* name, bool isOwner) = 0;
				virtual bool close() = 0;
				virtual bool send(const char* msg, size_t len, unsigned prio) = 0;
				virtual bool receive(char *msg, size_t len, unsigned* prio) = 0;
				virtual bool timedsend(const char* msg, size_t len, unsigned prio, 
						const struct timespec *abs_timeout) = 0;
				virtual bool timedreceive(char *msg, size_t len, unsigned* prio, 
						const struct timespec *abs_timeout) = 0;
				virtual bool notify(const struct sigevent* sevp) = 0;
				virtual bool getattr(struct mq_attr* attr) = 0;
				virtual bool setattr(struct mq_attr* newattr, struct mq_attr* oldattr) = 0;
				virtual bool unlink() = 0;
				virtual int getlasterror() = 0;
		};
	}
}

#endif //  __MESSAGE_QUEUE_IFS__H_
