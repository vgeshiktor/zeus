/**
 ** File Name : managerbase.h
 ** Purpose :                                                
 ** Creation Date : Nov 08, 2015
 ** Last Modified : Sun 20 Dec 2015 09:10:53 PM IST
 ** Created By : vadim
 **/

#include <memory>
#include <vector>
#include "managerifs.h"
#include "msgqueueifs.h"

namespace infra   
{
	namespace process   
	{
		class managerbase : public managerifs
		{
			public:
				managerbase();
				virtual ~managerbase();

				bool init(int argc, char* argv[]) final;
				void run() final;
				void sendselfquitmsg() final;

			protected:
				void parsecmdline(int argc, char* argv[]);
				void showhelp(const char* procname);
				void showversion(const char* procname);

			private:
				std::string buildQname(const char* name);
				bool init(const char*, uint16_t) final { return false; }
				void join() final {}
				void initprocname(const char* pname);

				std::string 								m_procname;
				std::unique_ptr<msgqueue::msgqueueifs>		m_queue;
				std::vector< std::unique_ptr<workerifs> > 	m_workers;
		};
	}
}
