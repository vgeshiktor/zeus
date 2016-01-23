/**
 ** File Name : mqwrapper.h
 ** Purpose :                                                
 ** Creation Date : Jan 02, 2016
 ** Last Modified : Sun 03 Jan 2016 09:43:54 PM IST
 ** Created By : vadim
 **/

#ifndef __MQ_WRAPPER_H__
#define __MQ_WRAPPER_H__

#include <memory>	// unique_ptr
#include <unordered_map>
#include "msgqueueifs.h"

namespace infra {
	namespace msgqueue {
		class mqwrapper 
		{
			public:
				mqwrapper();
				~mqwrapper();

				bool send(const char* qname, const char *msg, size_t len, unsigned prio);

			private:
				std::unordered_map<std::string,
					std::unique_ptr<msgqueue::msgqueueifs>> m_mqmap;
		};
	} // namespace msgqueue
} // namespace infra

#endif /* __MQ_WRAPPER_H__ */
