/**
 ** File Name : manager.cpp
 ** Purpose :                                                
 ** Creation Date : Nov 29, 2015
 ** Last Modified : Sun 29 Nov 2015 09:46:47 PM IST
 ** Created By : vadim
 **/

#include "manager.h"

namespace cerberus
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
