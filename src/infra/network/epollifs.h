/**
 ** File Name : epollifs.h
 ** Purpose :                                                
 ** Creation Date : Nov 16, 2015
 ** Last Modified : Tue 17 Nov 2015 12:28:47 PM IST
 ** Created By : vadim
 **/

#include <sys/epoll.h>

namespace infra
{
	namespace network
	{
		class epollifs
		{
			public:
				virtual bool epoll_create() = 0;
				virtual int epoll_create1(int flags) = 0;
				virtual int epoll_ctl(int op, int fd, struct epoll_event* event) = 0;
				virtual int epoll_ctl_add(int fd, struct epoll_event* event) = 0;
				virtual int epoll_ctl_modify(int fd, struct epoll_event* event) = 0;
				virtual int epoll_ctl_delete(int fd, struct epoll_event* event) = 0;
				virtual int epoll_wait(struct epoll_event* event, int maxevents, 
						int timeout) = 0;
				virtual int epoll_pwait(struct epoll_event* event, int maxevents, 
						int timeout, const sigset_t* sigmask) = 0;
		};
	}
}
