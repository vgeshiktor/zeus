/**
 ** File Name : mqwrapper.cpp
 ** Purpose :                                                
 ** Creation Date : Jan 02, 2016
 ** Last Modified : Sat 02 Jan 2016 11:01:32 PM IST
 ** Created By : vadim
 **/

#include "mqwrapper.h"
#include "mqposixfactory.h"

namespace infra {
	namespace msgqueue {
		mqwrapper::mqwrapper()
		{
		}

		mqwrapper::~mqwrapper()
		{
		}


		bool mqwrapper::send(const char* qname, const char *msg, size_t len, unsigned prio)
		{
			auto it = m_mqmap.find(qname);
			if(it != m_mqmap.end())
			{
				return it->second->send(msg, len, prio);
			}
			else 
			{
				mqposixfactory factory;
				std::unique_ptr<msgqueueifs> mq = factory.createmq();
				if(mq)
				{
					bool res = mq->open(qname, false);
					if(!res)
						return false;
					res = mq->send(msg, len, prio);
					m_mqmap[qname] = std::move(mq);
					return res;
				}
				else
					return false;
			}
		}

	} // namespace msgqueue
} // namespace infra
