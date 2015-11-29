/**
 ** File Name : workerbase.h
 ** Purpose :                                                
 ** Creation Date : Nov 29, 2015
 ** Last Modified : Sun 29 Nov 2015 03:57:02 PM IST
 ** Created By : vadim
 **/

#include "workerifs.h"

namespace process
{
	class workerbase : public workerifs
	{
		workerbase();
		virtual ~workerbase();

		bool init();
	};
}
