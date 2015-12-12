/**
 ** File Name : workerbase.cpp
 ** Purpose :                                                
 ** Creation Date : Nov 30, 2015
 ** Last Modified : Sat 05 Dec 2015 11:11:09 AM IST
 ** Created By : vadim
 **/

#include <sstream>
#include <string.h>
#include "workerbase.h"
#include "mqposixfactory.h"

#define MAX_MSG_SIZE 8192

namespace infra {
	namespace process
	{
		workerbase::workerbase()
		{
		}

		workerbase::~workerbase()
		{
		}

		bool workerbase::init(const char* name, uint16_t index)
		{
			// build worker message queue name
			std::string qname = buildQname(name, index);

			// create message queue object
			msgqueue::mqposixfactory factory;
			m_queue = factory.createmq();
			if(!m_queue)
				return false;

			// open message queue
			if(!m_queue->open(qname.c_str(), true))
				return false;

			// create thread for the worker 
			m_thread = std::thread(&workerbase::run, this);

			return true;
		}

		void workerbase::run()
		{
			unsigned prio;
			char mymsg[MAX_MSG_SIZE] = {0};

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
				}
			}
		}

		std::string workerbase::buildQname(const char* name, uint16_t index)
		{
			std::stringstream ss;
			ss << name << index;

			return ss.str();
		}
	}
}
