/**
 ** File Name : manager.h
 ** Purpose :                                                
 ** Creation Date : Nov 07, 2015
 ** Last Modified : Tue 15 Dec 2015 10:52:40 PM IST
 ** Created By : vadim
 **/

#include <stdio.h>
#include "managerbase.h"

namespace hermes
{
	class manager : public infra::process::managerbase
	{
		public:
			manager();
			virtual ~manager();

			bool init(int argc, char* argv[]);
			void run();
	};
}
