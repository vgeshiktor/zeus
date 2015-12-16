/**
 ** File Name : loggerproxy.cpp
 ** Purpose :                                                
 ** Creation Date : Dec 12, 2015
 ** Last Modified : Sat 12 Dec 2015 12:19:09 PM IST
 ** Created By : vadim
 **/

namespace infra {
	namespace logger {

		loggerproxy::loggerproxy()
		{
		}

		loggerproxy::~loggerproxy()
		{
		}

		void loggerproxy::log(int nLogLevel, char* msg)
		{
		}

		bool loggerproxy::isLevelEnabled(int nLogLevel)
		{
			return true;
		}

		void loggerproxy::forcedlog(int nLogLevel, char* msg)
		{
		}

		bool loggerproxy::init()
		{
			return true;
		}
	}
}
