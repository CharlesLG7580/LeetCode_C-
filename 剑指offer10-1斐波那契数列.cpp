#include<iostream>
using namespace std;

int fib(int n)
{
	 int a=0;
	int b=1;
	int c; 
	if(n==0)
		return 0;
	if(n==1||n==2)
	{
		return 1;
	}
	for(int i=2;i<=n;i++)
	{
		c=a%1000000007+b%1000000007;
		a=b;
		b=c;
	}
	return c%1000000007;
 } 
 int main()
 {
 	int n=2;
 	cout<<fib(n);
 }
