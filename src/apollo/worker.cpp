/**
 ** File Name : worker.cpp
 ** Purpose :                                                
 ** Creation Date : Dec 15, 2015
 ** Last Modified : Wed 16 Dec 2015 10:34:56 PM IST
 ** Created By : vadim
 **/

#include "worker.h"

namespace apollo {
	worker::worker()
	{
	}

	worker::~worker()
	{
	}

	void worker::processmsg(const char* msg, uint16_t /* len */)
	{
		printf("%s\n", msg);
	}
}

