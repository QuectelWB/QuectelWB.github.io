#include<stdio.h>

int Callback_1(int x) // Callback Function 1
{
	    printf("Hello, this is Callback_1: x = %d ", x);
	        return 0;
}

int Callback_2(int x) // Callback Function 2
{
	    printf("Hello, this is Callback_2: x = %d ", x);
	        return 0;
}

int Callback_3(int x) // Callback Function 3
{
	    printf("Hello, this is Callback_3: x = %d ", x);
	        return 0;
}

int Handle(int y, int (*Callback)(int))
{
	    printf("Entering Handle Function. ");
	        Callback(y);
		    printf("Leaving Handle Function. ");
}

int main()
{
    int a = 2;
    int b = 4;
    int c = 6;
    printf("Entering Main Function. ");
    Handle(a, Callback_1);
    Handle(b, Callback_2);
    Handle(c, Callback_3);
    printf("Leaving Main Function. ");
   return 0;
}
