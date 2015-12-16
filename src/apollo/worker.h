/**
 ** File Name : worker.h
 ** Purpose :                                                
 ** Creation Date : Dec 15, 2015
 ** Last Modified : Tue 15 Dec 2015 10:37:48 PM IST
 ** Created By : vadim
 **/

#ifndef __WORKER_H__
#define __WORKER_H__

#include "workerbase.h"

namespace apollo {
	class worker final : public infra::process::workerbase
	{
		public:
			worker();
			virtual ~worker();

		private:
			void processmsg(const char* msg, uint16_t len) final;
	};
}

#endif /*  __WORKER_H__ */
