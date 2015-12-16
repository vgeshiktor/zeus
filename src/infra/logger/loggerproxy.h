/**
 ** File Name : loggerproxy.h
 ** Purpose :                                                
 ** Creation Date : Dec 12, 2015
 ** Last Modified : Sat 12 Dec 2015 12:14:03 PM IST
 ** Created By : vadim
 **/

#ifndef __LOGGER_PROXY_H__
#define __LOGGER_PROXY_H__

#include "loggerifs.h"

namespace infra {
	namespace logger {
		class loggerproxy : public loggerifs
		{
			public:
				loggerproxy();
				virtual ~loggerproxy();

				void log(int nLogLevel, char* msg);
				bool isLevelEnabled(int nLogLevel);
				void forcedlog(int nLogLevel, char* msg);

				bool init();
		};
	}
}

#endif /*  __LOGGER_PROXY_H__ */
