/**
 ** File Name : epollimpl.h
 ** Purpose :                                                
 ** Creation Date : Nov 16, 2015
 ** Last Modified : Tue 17 Nov 2015 12:49:46 PM IST
 ** Created By : vadim
 **/

#include "epollifs.h"

namespace infra
{
	namespace network
	{
		class epollimpl : public epollifs
		{
			public:
				epollimpl();
				virtual ~epollimpl();

				bool epoll_create(); // depricated
				bool epoll_create1(int flags);
				bool epoll_ctl(int op, int fd, struct epoll_event* event);
				bool epoll_ctl_add(int fd, struct epoll_event* event);
				bool epoll_ctl_modify(int fd, struct epoll_event* event);
				bool epoll_ctl_delete(int fd, struct epoll_event* event);
				int epoll_wait(struct epoll_event* event, int maxevents, 
						int timeout);
				int epoll_pwait(struct epoll_event* event, int maxevents, 
						int timeout, const sigset_t* sigmask);

			private:
				int m_epfd;
				int m_errno;
		};
	}
}
