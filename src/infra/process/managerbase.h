/**
 ** File Name : managerbase.h
 ** Purpose :                                                
 ** Creation Date : Nov 08, 2015
 ** Last Modified : Sun 29 Nov 2015 03:50:01 PM IST
 ** Created By : vadim
 **/

#include "managerifs.h"

namespace process   
{
	class managerbase : public managerifs
	{
		public:
			managerbase();
			virtual ~managerbase();
			bool init();

		protected:
			void parsecmdline(int argc, char* argv[]);
			void showhelp(const char* procname);
			void showversion(const char* procname);
	};
}
