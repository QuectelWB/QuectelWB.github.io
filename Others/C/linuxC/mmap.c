#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
#define TRUE        1
#define FALSE       -1
#define FILE_SIZE   100

#define MMAP_FILE_PATH "./mmap.txt"

size_t get_file_size(const char* file_path)
{
    struct stat buf;
    if(stat(file_path, &buf)<0)
    {
          printf("%s[%d]:%s",__FUNCTION__,__LINE__,strerror(errno));
          return -1;
    }
    return buf.st_size;

}


int main(int argc, char** argv)
{
    	int fd = -1;
      //char buff[100]={0};
    	void *result;    
    	int lseek_result = -1;
    	int file_length = -1;

	// open 
    	fd = open(MMAP_FILE_PATH,O_RDWR|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    	if( -1==fd)
    	{
        	printf("open failed \n");
        	printf("%s\n", strerror(errno));
        	return FALSE;
	}


    	lseek_result = lseek(fd, FILE_SIZE-1, SEEK_SET);
    	if( -1 == lseek_result)
       	{
       		printf("lseek failed\n");
       		printf("%s\n", strerror(errno));
       		return FALSE;
      	}

    	write(fd,"\0",1);
    	lseek(fd,0,SEEK_SET);

   	file_length = get_file_size(MMAP_FILE_PATH);
   	if(-1 == file_length)
   	{
  		printf("get file size failed \n");
  		return FALSE;
  	}

 	printf("filesize = %d\n",file_length);

/**
 *
 * void* mmap(	void* addr, 
 * 			----> 0 
 * 		size_t size,
 * 		int prot,
 * 			----> 分配内存的权限，一般用PROT_READ|PROT_WRITE
 * 		int flags, 
 * 			----> MAP_SHARED   MAP_PRIVATE 
 * 			----> MAP_ANONYMOUS 
 *              int fd, 
 *              off_t offset)
 *
 * **/

	result = mmap(  0, \
			file_length, \
                 	PROT_READ|PROT_WRITE,\
 		 	MAP_SHARED,\
 		 	fd,\
			0);

	if( result == (void*)-1)
      	{
        	printf("mmap failed\n");
        	printf("%s\n", strerror(errno));
        	return FALSE;
  	}

	close(fd);

	strncpy(result, "hello world\n",file_length);

	printf("%s\n",result);

	//  ssize_t write(int fd, const void *buf, size_t count);
	write(fd,"A",2);

    	munmap(0, file_length);

    	return 0;
}


