

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include <errno.h>
 
/*****************Client****************/
 
int main(int argc, char **argv)
{
	int fd, ret, len;
	struct sockaddr_un un;
	char str[24] ;
	memset(str, 0, sizeof(str));
	strcpy(str, "Hello World!");
 
	//create socket
	fd = socket(AF_UNIX, SOCK_DGRAM, 0);
	if(fd<0)
	{
		printf("socket error\n");
		return -1;
	}
 
	//name the socket
	un.sun_family=AF_UNIX;
	strcpy(un.sun_path, argv[1]);
	len = sizeof(un);
 
	ret = sendto(fd, str, strlen(str)+1, 0, (struct sockaddr*)&un, sizeof(struct sockaddr_un));
	printf("ret = %d, errno = %d, %s\n", ret, errno, strerror(errno));
	return 0;
}

