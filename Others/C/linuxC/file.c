#include <string.h>
#include <stdio.h>
#include <fcntl.h>
int main()
{
  char *p1 = "This is a c test code";
  volatile int len = 0;
	     
  int fp = open("mmap.txt", O_RDWR|O_CREAT);

  printf("fp = %d \n",fp);

  for(;;)
  {
       int n;
        
       if(0==(n=write(fp, p1+len, (strlen(p1)-len))))   
       {       
	       	//if((n=write(fp, p1+len, 3)) == 0) 
		//strlen(p1) = 21
          	printf("n = %d \n", n);
          	break;
        }

       len+=n;
   }

 return 0;
}
