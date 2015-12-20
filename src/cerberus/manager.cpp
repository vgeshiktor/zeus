/**
 ** File Name : manager.cpp
 ** Purpose :                                                
 ** Creation Date : Nov 29, 2015
 ** Last Modified : Thu 17 Dec 2015 09:09:11 PM IST
 ** Created By : vadim
 **/

#include <stdio.h>
#include "manager.h"

namespace cerberus
{
	manager::manager()
	{
	}

	manager::~manager()
	{
	}

	void manager::processmsg(const char* msg, uint16_t)
	{
		printf("%s\n", msg);
	}
}
