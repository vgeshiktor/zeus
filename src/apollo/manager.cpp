/**
 ** File Name : manager.cpp
 ** Purpose :                                                
 ** Creation Date : Nov 08, 2015
 ** Last Modified : Sun 20 Dec 2015 10:10:25 PM IST
 ** Created By : vadim
 **/

#include "manager.h"
#include "worker.h"

namespace apollo
{
	manager::manager()
	{
	}

	manager::~manager()
	{
	}

	void manager::processmsg(const char* msg, uint16_t /* len */)
	{
		printf("%s\n", msg);	
	}

	std::unique_ptr<infra::process::workerifs> manager::createworker()
	{
		return std::unique_ptr<infra::process::workerifs>(new worker);
	}
}


