/**
 ** File Name : client.cpp
 ** Purpose :                                                
 ** Creation Date : Dec 20, 2015
 ** Last Modified : Sat 23 Jan 2016 02:17:57 AM IST
 ** Created By : vadim
 **/

#include <string.h>
#include "mqposiximpl.h"

int main(int argc, char* argv[])
{
	char* msg = 2 == argc ? argv[1] : (char*)"test message";

	printf("starting client, connecting to server mq=\"/apollo\"\n");
	infra::msgqueue::mqposiximpl mqclient;
	if(-1 == mqclient.open("apollo", false))
	{
		printf("failed to open client mq \"/apollo\"\n");
		return -1;
	}

	mq_attr attr = mq_attr();
	if(-1 == mqclient.getattr(&attr))
	{
		printf("failed to get queue attributes\n");
		return -1;
	}

	printf("current = %ld msg_max = %ld\nmsg_size = %ld\n",
			attr.mq_curmsgs, attr.mq_maxmsg,
			attr.mq_msgsize);

	{
		if(-1 == mqclient.send(msg, strlen(msg), 0))
		{
			printf("failed to send message to server\n");
			return -1;
		}
		else 
			printf("sent %s successfully\n", msg);
	}

	return 0;
}

