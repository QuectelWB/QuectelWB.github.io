#include<stdio.h>

// GNU gcc 没有reffrence 运算类型
//




void SwapX(int& x,int& y)
{
	printf("0x%p,0x%p\n",&x,&y);  // 内存地址和原来的其实一样的
	x = x^y;
	y = y^x;
	x = x^y;
}

int main()
{
	int a=1,b=2;

	printf("0x%p,0x%p\n",&a,&b);
	SwapX(a,b);

	printf("a=%d,b=%d\n",a,b);

	return 0;
}
