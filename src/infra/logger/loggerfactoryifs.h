/**
 ** File Name : loggerfactoryifs.h
 ** Purpose :                                                
 ** Creation Date : Dec 12, 2015
 ** Last Modified : Sat 12 Dec 2015 11:54:59 AM IST
 ** Created By : vadim
 **/

#ifndef __LOGGER_FACTORY_IFS_H__
#define __LOGGER_FACTORY_IFS_H__

#include "loggerifs.h"

namespace infra {
	namespace logger {
		class loggerfactoryifs 
		{
			public:
				virtual std::unique_ptr<loggerifs> createlogger() = 0;
		};
	}
}

#endif /* __LOGGER_FACTORY_IFS_H__ */
