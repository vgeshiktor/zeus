/**
 ** File Name : tcplistener.h
 ** Purpose :                                                
 ** Creation Date : Nov 16, 2015
 ** Last Modified : Mon 16 Nov 2015 10:08:55 AM IST
 ** Created By : vadim
 **/

namespace hermes
{
	class tcplistener
	{
		public:
			tcplistener();
			~tcplistener();

			bool init();
			void run();

		private:
			// readers thread pool
			// writers thread pool
	}
}
