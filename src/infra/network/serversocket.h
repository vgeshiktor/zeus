/**
 ** File Name : serversocket.h
 ** Purpose :                                                
 ** Creation Date : Nov 17, 2015
 ** Last Modified : Wed 18 Nov 2015 09:35:10 AM IST
 ** Created By : vadim
 **/

#include <string>

namespace infra
{
	namespace network
	{
		class serversocket
		{
			public:
				serversocket();
				~serversocket();

				bool create_and_bind(const char* port);
				bool make_non_blocking();

				int getfd()
				{ return m_sfd; }

			private:
				int m_sfd;
				int m_errno;
				std::string m_error;
		};
	}
}
