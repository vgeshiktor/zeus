/**
 ** File Name : workerifs.h
 ** Purpose :                                                
 ** Creation Date : Nov 29, 2015
 ** Last Modified : Sun 29 Nov 2015 03:48:07 PM IST
 ** Created By : vadim
 **/

namespace process
{
	class workerifs
	{
		public:
			virtual bool init() = 0;
			virtual void run() = 0;
	};
}

