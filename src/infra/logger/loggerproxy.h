/**
 ** File Name : loggerproxy.h
 ** Purpose :                                                
 ** Creation Date : Dec 09, 2015
 ** Last Modified : Thu 10 Dec 2015 12:01:53 AM IST
 ** Created By : vadim
 **/

#ifndef __LOGGER_PROXY_H__
#define __LOGGER_PROXY_H__
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
		};
	}
}
#endif /* __LOGGER_PROXY_H__ */


