#include<bits/stdc++.h>
using namespace std;

class myF
{
public:	
	int x=8;

	//
	void normal()
	{
	
    	int a=0,b=0,c=1,n;

    	n = x;//输入n

    	for(int i=1;i<=n-2;i++)
    	{
       		a=b;
       		b=c;
       		c=a+b;
		cout << "===========\n" ;
		cout << "i = " << i << endl;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "c = " << c << endl;
   	}
	cout<< c <<endl;//output
	}

	void arrway(){

	   	int a[30],i,n;
	   	n=x;

		// initial state  F(0)=0  F(1)=1

	   	a[0]=0;	
		a[1]=1;

	  	for(i=2;i<=n;i++)
	  	 {
	   		a[i]=a[i-2]+a[i-1];
//	 		cout << "a[" << i << "]= "<< a[i] << endl;
		 }


	  	cout<<a[n]<<endl;

	}	
};


int main()
{
	myF mytest1;
//	mytest1.x = 5;

//	mytest1.arrway();
	mytest1.normal();

	return 0;
}



