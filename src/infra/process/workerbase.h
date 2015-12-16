/**
 ** File Name : workerbase.h
 ** Purpose :                                                
 ** Creation Date : Nov 29, 2015
 ** Last Modified : Tue 15 Dec 2015 10:32:05 PM IST
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

				bool init(const char* name, uint16_t index) final;
				void run() final;
				void join() final;

			protected:
				bool createmq(const char* name);


			private:
				std::string buildQname(const char* name, uint16_t index);

				std::unique_ptr<msgqueue::msgqueueifs>	m_queue;
				std::thread								m_thread;	
		};
	}
}
