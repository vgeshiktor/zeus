/**
 ** File Name : managerbase.cpp
 ** Purpose :                                                
 ** Creation Date : Nov 08, 2015
 ** Last Modified : Tue 15 Dec 2015 10:12:38 PM IST
 ** Created By : vadim
 **/

#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include "config.h"
#include "managerbase.h"
#include "mqposixfactory.h"

#define MAX_MSG_SIZE 1024

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

		bool managerbase::init(int, char* argv[])
		{
			// build manager message queue name
			std::string qname = buildQname(argv[0]);

			// create message queue object
			infra::msgqueue::mqposixfactory factory;
			m_queue = factory.createmq();
			if(!m_queue)
				return false;

			// open message queue
			if(!m_queue->open(qname.c_str(), true))
				return false;

			// create workers
			int count = workerscount();
			m_workers.resize(count);
			for(int i = 0; i < count; i++)
				m_workers.push_back(createworker());

			// initialize workers
			auto i = 0;
			for(auto& worker : m_workers)
				worker->init(argv[0], i++);

			return true;
		}

		void managerbase::run()
		{
			unsigned prio;
			char mymsg[MAX_MSG_SIZE] = {0};

			// start all workers - currently started automatically

			// create message loop for the worker
			while(1)
			{
				if(m_queue->receive(mymsg, MAX_MSG_SIZE, &prio))
				{
					// check first for exit message
					if(0 == strcmp("quit", mymsg))
						break;
					else // process rest of the messages
						processmsg(mymsg, MAX_MSG_SIZE);
				}
				else
				{
					// TODO: error handling
					fprintf(stderr, "failed to receive message from message queue\n");
				}
			}

			// wait for all workers for finish
			for(auto& worker : m_workers)
				worker->join();
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

		std::string managerbase::buildQname(const char* name)
		{
			std::stringstream ss;
			ss << name;

			return ss.str();
		}
	}
}
