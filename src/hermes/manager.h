/**
 ** File Name : manager.h
 ** Purpose :                                                
 ** Creation Date : Nov 07, 2015
 ** Last Modified : Wed 16 Dec 2015 10:43:02 PM IST
 ** Created By : vadim
 **/

#include "workerifs.h"
#include "managerbase.h"

namespace hermes
{
	class manager : public infra::process::managerbase
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
