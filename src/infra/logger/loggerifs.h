/**
 ** File Name : loggerifs.h
 ** Purpose :                                                
 ** Creation Date : Dec 09, 2015
 ** Last Modified : Wed 09 Dec 2015 11:52:36 PM IST
 ** Created By : vadim
 **/

#ifndef __LOGGER_IFS_H__
#define __LOGGER_IFS_H__

namespace infra {
	namespace logger {
		class loggerifs
		{
			public:
				void log(int nLogLevel, char* msg) = 0;
				bool isLevelEnabled(int nLogLevel) = 0;
				void forcedlog(int nLogLevel, char* msg) = 0;
		};
	}
}

#endif /* __LOGGER_IFS_H__ */
