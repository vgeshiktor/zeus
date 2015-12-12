/**
 ** File Name : loggerifs.h
 ** Purpose :                                                
 ** Creation Date : Dec 07, 2015
 ** Last Modified : Mon 07 Dec 2015 11:19:58 PM IST
 ** Created By : vadim
 **/

#ifndef __LOGGER_IFS_H__
#define __LOGGER_IFS_H__

namespace infra {
	namespace logger {
		class loggerifs
		{
			public:
				void log();
				bool shouldlog();
				void forcelog();
		};
	}
}
#endif /* __LOGGER_IFS_H__ */
