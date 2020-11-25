/******

typedef char* va_list;

void va_start ( va_list ap, prev_param );  ANSI version 

type va_arg ( va_list ap, type );

void va_end ( va_list ap );
**/


#include <stdio.h>
#include <stdarg.h>

#define END -1
#define DEBUG

int va_sum (int first_num, ...)
{
	 va_list ap;
	int res=first_num;
	int temp=0;

	va_start(ap,first_num);

// END as end
	while((temp=va_arg(ap,int))!=END)
	{
#ifdef DEBUG
		printf("%3d ",temp);
#endif
		res += temp;
	}
	va_end(ap);

	        return res;
}

int main ()
{
	    int sum_val = va_sum(1, 2, 3, 4, 5, END);
	        printf ("%d\n", sum_val);
		    return 0;
}
