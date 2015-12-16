/**
 ** File Name : loggerifs.h
 ** Purpose :                                                
 ** Creation Date : Dec 09, 2015
 ** Last Modified : Sat 12 Dec 2015 12:12:05 PM IST
 ** Created By : vadim
 **/

#ifndef __LOGGER_IFS_H__
#define __LOGGER_IFS_H__

namespace infra {
	namespace logger {
		class loggerifs
		{
			public:
				virtual void log(int nLogLevel, char* msg) = 0;
				virtual bool isLevelEnabled(int nLogLevel) = 0;
				virtual void forcedlog(int nLogLevel, char* msg) = 0;
		};
	}
}

#endif /* __LOGGER_IFS_H__ */
