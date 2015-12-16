/**
 ** File Name : workerifs.h
 ** Purpose :                                                
 ** Creation Date : Nov 29, 2015
 ** Last Modified : Tue 15 Dec 2015 11:03:04 PM IST
 ** Created By : vadim
 **/

#ifndef __WORKER_IFS_H__
#define __WORKER_IFS_H__

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
				virtual void join() = 0;

			protected:
				virtual void processmsg(const char* msg, uint16_t len) = 0;
		};
	}
}

#endif /* __WORKER_IFS_H__ */
