#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <fcntl.h>

// typedef printf print;

// #define print printf

int (*print)(char*,...)=printf;

int main(void)
{
	int i;
	pid_t pid;
	pid = fork();
	
	if( pid == -1)
	{   
	     print("fork error\n");
	     return -1;
	}

	if(pid > 0 )
	{
		print("father\n");		//父进程返回值大于1
		exit(EXIT_SUCCESS);		//父线程退出    
	}

	if(setsid() == -1)
	 {   
	    	print("SETSID ERROR\n");
	    	return -1;
	}
	chdir("/"); 

	for( i = 0; i < 3; ++i) 		//关闭0,1,2文件描述符
	{
	  	close(i);
	  	open("/dev/null", O_RDWR);
	  	dup(0);
	  	dup(0);
	}

	umask(0);
 	return 0;

}
