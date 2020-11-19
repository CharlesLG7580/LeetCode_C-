#include<iostream>
using namespace std;

double myPow(double x, int n)  //最常见 的logn的算法就是分而治之
					//2的10次方，就是2的5次方的平方 
{
	
	double res=1;
	for(int i=n;i!=0;i/=2)
	{
		if(i%2!=0)
		{
			res=res*x;
		}
		x=x*x;
	 } 
	 return n<0?1/res:res;
}
int main()
{
	cout.setf(ios_base::fixed,ios_base::floatfield);  //一般cout会删除结尾的零
								//调用setf函数会覆盖这种行为，cout打印6位小数 
	double x=2.00000;
	int n=-2;
	cout<<myPow(x,n);  
}
