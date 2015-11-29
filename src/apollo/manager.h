/**
 ** File Name : manager.h
 ** Purpose :                                                
 ** Creation Date : Nov 29, 2015
 ** Last Modified : Sun 29 Nov 2015 04:12:18 PM IST
 ** Created By : vadim
 **/

#include <stdio.h>
#include "managerbase.h"

namespace apollo
{
	class manager : public process::managerbase
	{
		public:
			manager();
			virtual ~manager();

			bool init(int argc, char* argv[]);
			void run();
	};
}
