/**
 ** File Name : workerifs.h
 ** Purpose :                                                
 ** Creation Date : Nov 29, 2015
 ** Last Modified : Sat 05 Dec 2015 11:10:17 AM IST
 ** Created By : vadim
 **/

#include <inttypes.h>

namespace infra
{
	namespace process
	{
		class workerifs
		{
			public:
				virtual bool init(const char* name, uint16_t index) = 0;
				virtual void run() = 0;

			protected:
				virtual bool createmq(const char* name) = 0;
				virtual void processmsg(const char* msg, uint16_t len) = 0;
		};
	}
}

