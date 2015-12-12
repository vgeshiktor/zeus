/**
 ** File Name : mqfactoryifs.h
 ** Purpose :                                                
 ** Creation Date : Dec 02, 2015
 ** Last Modified : Fri 04 Dec 2015 06:37:58 PM IST
 ** Created By : vadim
 **/

#ifndef __MQ_FACTORY_H__
#define __MQ_FACTORY_H__

#include "msgqueueifs.h"

namespace infra
{
	namespace msgqueue
	{
		class mqfactoryifs
		{
			public:
				virtual std::unique_ptr<msgqueueifs> createmq() = 0;
		};
	}
}

#endif // __MQ_FACTORY_H__
