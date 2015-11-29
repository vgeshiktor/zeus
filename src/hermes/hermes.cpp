/**
 ** File Name : hermes.cpp
 ** Purpose :                                                
 ** Creation Date : Nov 07, 2015
 ** Last Modified : Mon 09 Nov 2015 12:18:03 PM IST
 ** Created By : vadim
 **/

#include <stdio.h>
#include "manager.h"

using namespace hermes;

int main(int argc, char* argv[])
{
	hermes::manager manager;

	if(manager.init(argc, argv))
		manager.run();
	else
		return -1;

	printf("finishing hermes server\n");
	return 0;
}

