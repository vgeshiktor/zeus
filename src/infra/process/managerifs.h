/**
 ** File Name : managerifs.h
 ** Purpose :                                                
 ** Creation Date : Nov 08, 2015
 ** Last Modified : Mon 30 Nov 2015 03:32:29 PM IST
 ** Created By : vadim
 **/

#include "workerifs.h"

namespace infra
{
	namespace process
	{
		class managerifs : public workerifs
		{
			public:
				virtual bool init(int argc, char* argv[]) = 0;
				virtual void run() = 0;

			protected:
				virtual void parsecmdline(int argc, char* argv[]) = 0;
				virtual void showhelp(const char* procname) = 0;
				virtual void showversion(const char* procname) = 0;
		};
	}
}

