/******************************
 *
 *
 *
 *
 * 在linux的网络编程中，很长的时间都在使用select来做事件触发。在linux新的内核中，有了一种替换它的机制，就是epoll。
 * 相比于select，epoll最大的好处在于它不会随着监听fd数目的增长而降低效率。因为在内核中的select实现中，它是采用轮询来处理的，轮询的fd数目越多，自然耗时越多。并且，在linux/posix_types.h头文件有这样的声明：
 * #define __FD_SETSIZE    1024
 * 表示select最多同时监听1024个fd
 *
 *
 *
 *
 * **************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<malloc.h>
#include<sys/epoll.h>

#define MAX_EVENTS 64



/***********************
 *
 * 创建一个epoll的句柄，size用来告诉内核这个监听的数目一共有多大
 * 当创建好epoll句柄后，它就是会占用一个fd值，在linux下如果查看/proc/进程id/fd/，是能够看到这个fd的
 *
 *
 *
 * *********/

//	epfd = epoll_create(1);




/****************
	 *
	 *
	 *
	 *int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);

	 epoll的事件注册函数，epoll_ctl向 epoll对象中添加、修改或者删除感兴趣的事件，返回0表示成功，否则返回1，此时需要根据errno错误码判断错误类型。
	 *
	 * ******************/

//	ret = epoll_ctl(epfd,EPOLL_CTL_ADD,STDIN_FILENO,&event);

		
//	nr_ev = epoll_wait(epfd,event1,MAX_EVENTS,-1);



int main()
{
 	int epfd,ret,nr_ev,i;
 	struct epoll_event event;
 	struct epoll_event *event1;
 	extern int errno;

	 epfd = epoll_create(1);
	 if(epfd < 0)
 	{
		  perror("epoll_create");
		  return -1;
	 }

	 event.data.fd = STDIN_FILENO;
	 event.events = EPOLLIN;

	 ret = epoll_ctl(epfd,EPOLL_CTL_ADD,STDIN_FILENO,&event);
	 if(ret == -1)
	 {
	 	 perror("epoll_ctl");
	 	 return -1;
	 }

	 event1 = malloc(sizeof(struct epoll_event)*MAX_EVENTS);
	 if(!event1)
	 {
	 	 perror("malloc");
	 	 return 1;
	 }

	 nr_ev = epoll_wait(epfd,event1,MAX_EVENTS,-1);
	 if(nr_ev < 0)
	 {
		  perror("epoll_wait");
	 	 return -1;
	 }
	 else
	 {
		 for(i=0;i<nr_ev;i++)
		 {
	  		printf("event = %d on fd = %d\n",event1[i].events,event1[i].data.fd);
	  		if(event1[i].events & EPOLLIN )
	  		{
	   			printf("Event occured in stdin \n");
	   			close(event1[i].data.fd);
				continue;
//break;
	  		}
		 }
	 }

	 close(STDIN_FILENO);

	 errno = 0;
	 free(event1);
	
	 if(errno)
		  printf("error on free");

	 return 0;

}
