/**
 ** File Name : manager.cpp
 ** Purpose :                                                
 ** Creation Date : Nov 08, 2015
 ** Last Modified : Wed 16 Dec 2015 10:44:02 PM IST
 ** Created By : vadim
 **/

#include <stdio.h>
#include "manager.h"

namespace hermes
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
		return std::unique_ptr<infra::process::workerifs>((workerifs*)NULL);
	}
}
