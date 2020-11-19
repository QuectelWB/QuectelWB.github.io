///a//a
//
/**
 *       #include <stdio.h>
 *
 *       int scanf(const char *format, ...);
 *       int fscanf(FILE *stream, const char *format, ...);
 *       int sscanf(const char *str, const char *format, ...);
 *	
 *	输出文件中的第一行
 * ***/

#include <stdio.h>

int main()
{
	
	
	
	
	char c[1000];
    	FILE *fptr;
     
   	if ((fptr = fopen("runoob.txt", "r")) == NULL)
 	{
     		printf("Error! opening file\n");
	            // 文件指针返回 NULL 则退出
		return -1;        
    	}
#if 0				    //              
          // 读取文本，直到碰到新的一行开始
    	fscanf(fptr,"%[^\n]", c);
#else   
	// 设置分隔符为字符.
	fscanf(fptr,"%[^.]", c);
#endif
    	printf("读取内容:\n%s\n", c);

#if 1 // 再读一次看看
//	fscanf(fptr,"%[^\n]", c);
	fscanf(fptr,"%[^c]", c);

    	printf("读取内容:\n%s\n", c);
#endif
	fclose(fptr);
	return 0;
}





