/**
 ** File Name : manager.h
 ** Purpose :                                                
 ** Creation Date : Nov 29, 2015
 ** Last Modified : Thu 17 Dec 2015 09:07:28 PM IST
 ** Created By : vadim
 **/

#include <stdio.h>
#include "managerbase.h"

namespace cerberus
{
	class manager : public infra::process::managerbase
	{
		public:
			manager();
			virtual ~manager();

		private:
			void processmsg(const char* msg, uint16_t);

			int workerscount()
			{ return 0; }

			std::unique_ptr<infra::process::workerifs> createworker()
			{ return NULL; }
	};
}
