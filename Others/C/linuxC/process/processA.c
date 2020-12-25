#include <unistd.h>  
      
int main(int argc,char*argv[])
{
#if 0
       execl("/bin/ls","ls","-l","/etc",(char *)0);
#endif

#if 0
       // int execv(const char *path， char *const argv[]);
       execv("/bin/ls",argv);
#endif


       return 0;  
}  
