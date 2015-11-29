/**
 ** File Name : manager.cpp
 ** Purpose :                                                
 ** Creation Date : Nov 08, 2015
 ** Last Modified : Sun 29 Nov 2015 04:22:17 PM IST
 ** Created By : vadim
 **/

#include "manager.h"

namespace apollo
{
	manager::manager()
	{
	}

	manager::~manager()
	{
	}

	bool manager::init(int argc, char* argv[])
	{
		// parse command line
		parsecmdline(argc, argv);

		// create message queue to manage this process

		// create workers

		return true;
	}

	void manager::run()
	{
		// start all workers

		// process message queue messages

		// wait for all workers to finish
	}
}
