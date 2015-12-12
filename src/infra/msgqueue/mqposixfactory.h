/**
 ** File Name : mqposixfactory.h
 ** Purpose :                                                
 ** Creation Date : Dec 02, 2015
 ** Last Modified : Fri 04 Dec 2015 06:40:22 PM IST
 ** Created By : vadim
 **/

#ifndef __MQ_POSIX_FACTORY__H_
#define __MQ_POSIX_FACTORY__H_

#include "mqfactoryifs.h"
#include "mqposiximpl.h"

namespace infra
{
	namespace msgqueue
	{
		class mqposixfactory : public mqfactoryifs
		{
			public:
				mqposixfactory()
				{
				}

				std::unique_ptr<msgqueueifs> createmq()
				{
					return std::unique_ptr<msgqueueifs>(new mqposiximpl);
				}
		};
	} // namespace msgqueue
} // namespace infra

#endif // __MQ_POSIX_FACTORY__H_
