/**
 ** File Name : manager.cpp
 ** Purpose :                                                
 ** Creation Date : Nov 08, 2015
 ** Last Modified : Sun 03 Jan 2016 11:10:55 PM IST
 ** Created By : vadim
 **/

#include "manager.h"
#include "worker.h"

namespace apollo
{
	manager::manager() : m_currThread(0), m_qname("apollo0")
	{
	}

	manager::~manager()
	{
	}

	void manager::processmsg(const char* msg, uint16_t len)
	{
		m_qname[6] = '0' + m_currThread++ % 3;
		printf("sending message to %s\n", m_qname.c_str());	
		m_mqwrapper.send(m_qname.c_str(), msg, len, 0);
	}

	std::unique_ptr<infra::process::workerifs> manager::createworker()
	{
		return std::unique_ptr<infra::process::workerifs>(new worker);
	}
}


