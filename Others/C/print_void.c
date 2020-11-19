/**********
 *
 * 如何打印出void * 指向的数据
 * 内核中许多数据指向的缓冲就是void *
 *
 *
 * ******/

#include <stdio.h>

int main()
{
#if 0
	int *p1,a=1;
	void *p2;
	p1=&a;
	p2=p1;

	//	printf("%d\n",*p1);  // 1 OK
	//	printf("%d",*p2);  // wrong , cannot build pass

	printf("p2: %d\n",*(int*)p2 );

	/**
	 *
	 * 将p2指向的4个字节的内容全部打印出来
	 *
	 * */

	printf("p2: %d\n",*(char*)p2 );

#endif

#if 1

	char p1[]="hello";
	void *p2;
	p2=p1;

	printf("[%s]: p2 . %c \n",__func__,*(char*)p2 );
	printf("[%s]: p2 . %c \n",__func__,*((char*)p2+1) );

	printf("[%s]: p2 . %x \n",__func__,*((char*)p2+2) );
#endif

	return 0;
}
