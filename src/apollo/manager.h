/**
 ** File Name : manager.h
 ** Purpose :                                                
 ** Creation Date : Nov 29, 2015
 ** Last Modified : Sun 03 Jan 2016 10:02:23 PM IST
 ** Created By : vadim
 **/

#include <memory>
#include <string>
#include "mqwrapper.h"
#include "managerbase.h"

namespace apollo
{
	class manager final : public infra::process::managerbase
	{
		public:
			manager();
			virtual ~manager();

		private: 	
			// currently hard coded, 
			// will be taken from configuration lately
			int workerscount() 
			{ return 3; }

			void processmsg(const char* msg, uint16_t len);
			std::unique_ptr<infra::process::workerifs> createworker();

			infra::msgqueue::mqwrapper m_mqwrapper;
			uint64_t m_currThread;
			std::string m_qname;
	};
}
