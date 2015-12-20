/**
 ** File Name : client.cpp
 ** Purpose :                                                
 ** Creation Date : Dec 20, 2015
 ** Last Modified : Sun 20 Dec 2015 10:11:11 PM IST
 ** Created By : vadim
 **/

#include <string.h>
#include "mqposiximpl.h"

int main(int argc, char* argv[])
{
	char* msg = 2 == argc ? argv[1] : (char*)"test message";

	printf("starting client, connecting to server mq=\"/apollo\"\n");
	infra::msgqueue::mqposiximpl mqclient;
	if(!mqclient.open("apollo", false))
	{
		printf("failed to open client mq \"/apollo\" error code:%d\n",
				mqclient.getlasterror());
		return -1;
	}

	mq_attr attr = mq_attr();
	if(!mqclient.getattr(&attr))
	{
		printf("failed to get queue attributes\n");
		return -1;
	}

	printf("msg_max = %ld\nmsg_size = %ld\n", attr.mq_maxmsg,
			attr.mq_msgsize);

	{
		if(!mqclient.send(msg, strlen(msg), 0))
		{
			printf("failed to send message to server, error code:%d\n",
					mqclient.getlasterror());
			return -1;
		}
		else 
			printf("sent %s successfully\n", msg);
	}

	return 0;
}

