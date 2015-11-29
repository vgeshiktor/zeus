/**
 ** File Name : epollimpl.cpp
 ** Purpose :                                                
 ** Creation Date : Nov 16, 2015
 ** Last Modified : Tue 17 Nov 2015 09:30:00 PM IST
 ** Created By : vadim
 **/

#include <errno.h>
#include "epollimpl.h"

namespace infra
{
	namespace network
	{
		epollimpl::epollimpl() : m_epfd(-1), m_errno(-1)
		{
		}

		epollimpl::~epollimpl()
		{
			m_epfd = -1;
			m_errno = 0;
		}

		bool epollimpl::epoll_create()
		{
			m_epfd = epoll_create(1); // the size argument is ignored, but must be > 0
			m_errno = errno;

			return -1 != m_epfd;
		}

		bool epollimpl::epoll_create1(int flags)
		{
			m_epfd = epoll_create1(flags);
			m_errno = errno;

			return -1 != m_epfd;
		}

		bool epollimpl::epoll_ctl(int op, int fd, struct epoll_event* event)
		{
			if(-1 == m_epfd)
			{
				m_errno = EBADF;
				return false;
			}

			int res = epoll_ctl(m_epfd, fd, event);
			m_errno = errno;

			return -1 != res;
		}

		bool epollimpl::epoll_ctl_add(int fd, struct epoll_event* event)
		{
			return epoll_ctl(EPOLL_CTL_ADD, fd, event);
		}

		bool epollimpl::epoll_ctl_modify(int fd, struct epoll_event* event)
		{
			return epoll_ctl(EPOLL_CTL_MOD, fd, event);
		}

		bool epollimpl::epoll_ctl_delete(int fd, struct epoll_event* event)
		{
			return epoll_ctl(EPOLL_CTL_DEL, fd, event);
		}

		int epollimpl::epoll_wait(struct epoll_event* event, int maxevents, 
				int timeout)
		{
			if(-1 == m_epfd)
			{
				m_errno = EBADF;
				return false;
			}

			int res = epoll_wait(m_epfd, event, maxevents, timeout);
			m_errno = errno;

			return -1 != res;
		}

		int epollimpl::epoll_pwait(struct epoll_event* event, int maxevents, 
				int timeout, const sigset_t* sigmask)
		{
			if(-1 == m_epfd)
			{
				m_errno = EBADF;
				return false;
			}

			int res = epoll_pwait(m_epfd, event, maxevents, timeout, sigmask);
			m_errno = errno;

			return -1 != res;
		}
	}
}
