/**
 ** File Name : apollo.cpp
 ** Purpose :                                                
 ** Creation Date : Nov 29, 2015
 ** Last Modified : Sun 29 Nov 2015 01:49:09 PM IST
 ** Created By : vadim
 **/

#include <stdio.h>
#include "manager.h"

using namespace apollo;

int main(int argc, char* argv[])
{
	apollo::manager manager;

	if(manager.init(argc, argv))
		manager.run();
	else
		return -1;

	printf("finishing apollo server\n");
	return 0;
}

