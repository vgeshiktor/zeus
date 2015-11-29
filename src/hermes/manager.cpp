/**
 ** File Name : manager.cpp
 ** Purpose :                                                
 ** Creation Date : Nov 08, 2015
 ** Last Modified : Mon 09 Nov 2015 11:02:52 AM IST
 ** Created By : vadim
 **/

#include "manager.h"

namespace hermes
{
	manager::manager()
	{
	}

	manager::~manager()
	{
	}

	bool manager::init(int argc, char* argv[])
	{
		parsecmdline(argc, argv);
		return true;
	}

	void manager::run()
	{
	}
}
