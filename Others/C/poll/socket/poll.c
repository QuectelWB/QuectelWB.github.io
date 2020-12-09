
#include <stdio.h>	
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <poll.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
 
/*****************Server****************/ 
 
#define MAX_BUFFER_SIZE 1024
#define IN_FILES 2
 
int main(int argc ,char **argv)
{
	struct pollfd fds[IN_FILES];
	char buf[MAX_BUFFER_SIZE] = "", domain[32] = "";
	int i;
	int ret;
	int server_sockfd[IN_FILES];
	int server_len[IN_FILES];
	struct sockaddr_un server_address[IN_FILES];
	
	for(i=0; i<IN_FILES; i++)
	{
		//create server socket
		sprintf(domain, "udp_tmp%d", i);
		unlink(domain);
		server_sockfd[i] = socket(AF_UNIX, SOCK_DGRAM, 0);
		if(server_sockfd[i]<0)
		{
			printf("socket error\n");
			return -1;
		}
		//name the socket
		server_address[i].sun_family = AF_UNIX;
		strcpy(server_address[i].sun_path, domain);
		server_len[i] = sizeof(server_address[i]);
		bind(server_sockfd[i], (struct sockaddr *)&server_address[i], server_len[i]);
	}
	//set the fd and events in poll listen pool
	for (i = 0; i < IN_FILES; i++)
        {
		fds[i].fd = server_sockfd[i];
		fds[i].events = POLLIN;
        }
	while(1)
        {
		if (poll(fds, IN_FILES, -1) <= 0)
		{
			printf("Poll error\n");
			return 1;
		}
		printf("********************\n");
		for (i = 0; i< IN_FILES; i++)
		{
			printf("%d.revents = %d\n", i+1, fds[i].revents);
			if ((fds[i].revents & POLLIN) != 0)
			{
				//accept a connection
				ret = recvfrom(server_sockfd[i], buf, 1024, 0, (struct sockaddr *)&server_address[i], (socklen_t *)&server_len[i]);
				//write and read by socket fd
				buf[ret]= '\0';
				printf("char from client is %s\n", buf);
			}
		}
	}
	//close
	for (i = 0; i < IN_FILES; i++)
	{
		close(server_sockfd[i]);
		sprintf(domain, "udp_tmp%d", i);
		unlink(domain);
	}
	return 0;
}
