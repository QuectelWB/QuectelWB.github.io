// Armstrong n位数的各位数的n次方之和等于该数
//
#include <stdio.h>

int check_bit(int);
int sumb(int,int);

// #define DEBUG

#define DEBUG_2

int main()
{
	
	int i=1,x,n;
	
	//先判断i 是几位数 --> n
	//x 是i和n计算得出的结果
	//判断x和i是否相等

#if 0
	for(i=1;i++;i<10000)
		{
			n=check_bit(i);
			x=sumb(i,n);
			if(x==i)
				printf("%d\t\n",i);
		}
#endif

#ifdef DEBUG_2
//	printf("%s,%d\n",__func__,check_bit(12346));
	printf("%s,%d\n",__func__,sumb(123,3));
#endif
	

	return 0;
}


int check_bit(int input){
	int n=0;

#ifdef DEBUG
	printf("[%s]%d\t\n",__func__,input);
#endif
	while(input>0)
	{
		n++;
		input=input/10;
	}
#ifdef DEBUG
	printf("[%s]%d\t\n",__func__,n);
#endif
	return n;
}


int sumb(int input,int n)
{
	int sum=0;
	int i=0;
	int tmp=0; //input 的第i位数
	int j=0;
	int t=0;

	printf("[%s]%d,%d\n",__func__,input,n);
	
	for(i=0;i<n;i++)
	{
		//通过 求余数
		tmp=input% 10 ;//最低一位数

		printf("[%s] tmp:%d\n",__func__,tmp);

		j=tmp;
		for(t=1;t<=i+1;t++)
		{
			tmp*=j;
			sum+=tmp;
			printf("[%s] tmp:%d\n",__func__,tmp);
		}		
		input=input/10;
		
	}

	return sum;
	
}
