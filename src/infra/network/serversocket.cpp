/**
 ** File Name : serversocket.cpp
 ** Purpose :                                                
 ** Creation Date : Nov 17, 2015
 ** Last Modified : Wed 18 Nov 2015 10:06:07 AM IST
 ** Created By : vadim
 **/

#include "serversocket.h"

namespace infra
{
	namespace network
	{
		serversocket::serversocket() : m_sfd(-1), m_errno(0)
		{
		}

		serversocket::~serversocket()
		{
			close();
		}

		void serversocket::close()
		{
			if(-1 != m_sfd)
			{
				close(m_sfd);
				m_sfd = -1;
			}
		}

		bool serversocket::create_and_bind(const char* port)
		{
			if(-1 != m_sfd)
			{
				m_errno = 0;
				return true;
			}

			struct addrinfo hints = {0};
			struct addrinfo* result;
			struct addrinfo* rp;

			hints.ai_family 	= AN_UNSPEC;	// return IPv4 and IPv6 choices
			hints.ai_socktype	= SOCK_STREAM;	// we want a TCP socket
			hints.ai_flags		= AI_PASSIVE;	// all interfaces

			int res = getaddrinfo(NULL, port, &hints, result);
			if(0 != res )
			{
				std::stringstream ss;
				ss << "getaddrinfo: " << gai_strerror(res) << std::endl;
				m_error = ss.str();
				return false;
			}

			for(rp = result; NULL != rp; rp = rp->ai_next)
			{
				m_sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
				if( -1 == m_sfd )
					continue;

				res = bind(m_sfd, rp->ai_addr, rp->ai_addrlen);
				if ( 0 == res )
					break; // we managed to bind successfully

				close(m_sfd);
			}

			if( !rp )
			{
				m_error = "Couldn't bind\n";
				m_errno = errno;
				return false;
			}

			freeaddrinfo(result);

			m_errno = errno;

			return true;
		}

		bool serversocket::make_non_blocking()
		{
			if(-1 != m_sfd)
			{
				m_errno = 0;
				return true;
			}

			int flags, res;

			flags = fcntl(m_sfd, F_GETFL, 0);
			if( -1 == flags )
			{
				m_errno = errno; 
				return false;
			}

			flags |= O_NONBLOCK;
			res = fcntl(m_sfd, F_SETFL, flags);
			if( -1 == flags )
			{
				m_errno = errno;
				return false;
			}

			m_errno = errno;

			return true;
		}
	}
}
