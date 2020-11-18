#include <stdio.h>  
int main()  
{  
    char c;

    /***
    scanf("%c", &c);  
   printf("%d\n", c);  
	
fflush(stdin); // 在GCC里无用

   scanf("%c", &c);  
    printf("%d\n", c);  

*/

        do {
		c = getchar();
	} while (c != '\n' && c != EOF);

    printf("%d\n", c);  

        do {
		c = getchar();
	} while (c != '\n' && c != EOF);

    printf("%d\n", c);  
    return 0;  
				  
}  
