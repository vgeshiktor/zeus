/**
 ** File Name : cerberus.cpp
 ** Purpose :                                                
 ** Creation Date : Nov 29, 2015
 ** Last Modified : Sun 29 Nov 2015 09:43:05 PM IST
 ** Created By : vadim
 **/

#include <stdio.h>
#include "manager.h"

using namespace cerberus;

int main(int argc, char* argv[])
{
	cerberus::manager manager;

	if(manager.init(argc, argv))
		manager.run();
	else
		return -1;

	printf("finishing  cerberus\n");
	return 0;
}

