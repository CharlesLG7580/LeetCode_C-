#include<iostream>
#include<vector>
using namespace std;

//用两个数组，一个存放奇数，一个存放偶数 ，一个存放结果 
 //然后遍历存入就可以了 
vector<int> test01(vector<int> &A)   //这个&符号就是一个引用可以保护内存里的一些东西。 
{
	vector<int> a,b,c;
	vector<int>::iterator itBegin=A.begin();
	vector<int>::iterator itEnd=A.end();
	while(itBegin!=itEnd)  //把偶数和奇数分开 
	{
		if(*itBegin%2==0)
		{
			
			a.push_back(*itBegin);
		}
		else
		{
			b.push_back(*itBegin);
		}
		itBegin++;
	}
	int m=0;
	for(int i=0;i<A.size();i++)   //新学习的利用下标遍历vector数组 
	{
		c.push_back(a.at(m));    
		c.push_back(b.at(m));
		m++;			//
		i++;			//利用m来一次push两个，再用i来让遍历一次走两个 
	}
	return c;
	
}
int main()
{
	vector<int> a={4,2,5,7};
	vector<int>c;
	c=test01(a);
	for(int i=0;i<c.size();i++)
	cout<<c.at(i);
}
