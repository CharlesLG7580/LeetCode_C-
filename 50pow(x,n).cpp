#include<iostream>
using namespace std;

double myPow(double x, int n)  //��� ��logn���㷨���Ƿֶ���֮
					//2��10�η�������2��5�η���ƽ�� 
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
	cout.setf(ios_base::fixed,ios_base::floatfield);  //һ��cout��ɾ����β����
								//����setf�����Ḳ��������Ϊ��cout��ӡ6λС�� 
	double x=2.00000;
	int n=-2;
	cout<<myPow(x,n);  
}
