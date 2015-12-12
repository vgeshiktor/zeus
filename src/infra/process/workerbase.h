/**
 ** File Name : workerbase.h
 ** Purpose :                                                
 ** Creation Date : Nov 29, 2015
 ** Last Modified : Sat 05 Dec 2015 11:15:25 AM IST
 ** Created By : vadim
 **/

#include <string>
#include <thread>
#include "workerifs.h"
#include "msgqueueifs.h"

namespace infra
{
	namespace process
	{
		class workerbase : public workerifs
		{
			public:

				workerbase();
				virtual ~workerbase();

				bool init(const char* name, uint16_t index);
				void run();

			protected:
				bool createmq(const char* name);

			private:
				std::string buildQname(const char* name, uint16_t index);

				std::unique_ptr<msgqueue::msgqueueifs>	m_queue;
				std::thread								m_thread;	
		};
	}
}
