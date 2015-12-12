/**
 ** File Name : managerbase.cpp
 ** Purpose :                                                
 ** Creation Date : Nov 08, 2015
 ** Last Modified : Mon 30 Nov 2015 03:33:22 PM IST
 ** Created By : vadim
 **/

#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "managerbase.h"

namespace infra
{
	namespace process
	{
		managerbase::managerbase()
		{
		}

		managerbase::~managerbase()
		{
		}

		bool managerbase::init()
		{
			return true;
		}

		void managerbase::parsecmdline(int argc, char* argv[])
		{
			int opt, option_index;

			static struct option long_options[] =
			{
				{ "help", 		no_argument, 0, 'h' },
				{ "version", 	no_argument, 0, 'v' },
				{ 0,			0,			 0,	 0	}
			};

			while((opt = getopt_long(argc, argv, "hv", long_options, &option_index)) != -1)
			{
				switch(opt)
				{
					case 'h':
						showhelp(argv[0]);
						exit(0);
						break;

					case 'v':
						showversion(argv[0]);
						exit(0);
						break;

					default: /* '?' */
						// unknown option re-parse options in derived class
						break;
				}
			}
		}

		void managerbase::showhelp(const char* procname)
		{
			char* pname;

			if(!procname || !procname[0])
				pname = (char*)PACKAGE;
			else
			{
				pname = (char*)strrchr(procname, '/');
				if(pname && pname[0] && pname[1])
					pname++;
				else
					pname = (char*)PACKAGE;
			}

			printf("%s [--help] [-h] [--version] [-v]\n"
					"--help, -h\t\t - show this help screen\n"
					"--version, -v\t\t - show version info\n",
					pname);
		}
		void managerbase::showversion(const char* procname)
		{
			char* pname;

			if(!procname || !procname[0])
				pname = (char*)PACKAGE;
			else
			{
				pname = (char*)strrchr(procname, '/');
				if(pname && pname[0] && pname[1])
					pname++;
				else
					pname = (char*)PACKAGE;
			}

			printf("GNU %s %s\n"
					"Copyright (C) 2007 Free Software Foundation, Inc.\n"
					"License GPLv3+: GNU GPL version 3 or later\n"
					"<http://gnu.org/licenses/gpl.html>\n"
					"This is free software: you are free to change and redistribute it.\n"
					"There is NO WARRANTY, to the extent permitted by law.\n",
					pname,
					PACKAGE_VERSION);
		}
	}
}
