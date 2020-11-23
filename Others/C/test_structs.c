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

union data{
	    int n;	//4
	    char ch;	//1
	    double f;	//8
};
union data a, b, c;

int main()
{
	struct myStruct1 S1;
	struct myStruct2 S2;
	
#if 0
	printf("sizeof s1 = %d, sizeof s2 = %d \n",
			sizeof(S1),
			sizeof(S2)
			);

	printf("sizeof a = %d \n",sizeof(a));
#endif

#if 0
	// 打印联合体的地址
	printf("0x%p\t%p\t%p\n",	
		&(a.n),&(a.ch),&(a.f)	);
	// 地址相同

#endif	

#if 1
	// 打印联合体的地址
	printf("0x%p\t%p\t%p\n",	
		&(S1.a),	//0x7ffffc320308
		&(S2.b),	//0x7ffffc3202fc
		&(S2.c)	);	//0x7ffffc320304
	// 内核栈空间，地址是从高地址往低地址分配

	// 

#endif	


	return 0;
}
