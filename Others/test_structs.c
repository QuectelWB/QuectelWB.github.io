#include<stdio.h>

struct myStruct1{
	int a;
	char b;
	short c;
};

struct myStruct2{
	char b;
	int a;
	short c;
};

int main()
{
	struct myStruct1 S1;
	struct myStruct2 S2;
	
	printf("sizeof s1 = %d, sizeof s2 = %d \n",
			sizeof(S1),
			sizeof(S2)
			);

	return 0;
}
