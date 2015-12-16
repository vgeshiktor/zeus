/**
 ** File Name : manager.h
 ** Purpose :                                                
 ** Creation Date : Nov 29, 2015
 ** Last Modified : Tue 15 Dec 2015 11:00:12 PM IST
 ** Created By : vadim
 **/

#include <memory>
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
	};
}
