#include<iostream>
#include<vector>
using namespace std;

//首先找到规律，前两行可以做初始化，从第三行开始，第三行的第二个数开始每一个数都是上一行的坐标减1+当前坐标，所以就每次添加完就
 //就复制一份b作为上一行来求新的一行a，接下来就要考虑一些边界问题，比如第一个和最后一个都是1，还有数组越界问题 
void test01(int numRows) 
{
	vector<int> a,b;
	a.push_back(1);  //初始化这是1 
	vector<vector<int> > result;
	for(int i=0;i<numRows;i++)
	{
		if(i==1)
		{
			a.push_back(1);
			b.assign(a.begin(), a.end());
		}
		else if(i!=0)
		{
			for(int j=0;j<=i;j++)
			{
				if(j==0)
				{
					a[j]=1;
				}
				else if(j==i)  //边界问题 
				{
					a.push_back(1);
				}
				else
				{
					if(j>=a.size())  //解决数组越界问题 
					{
						a.push_back(b[j-1]+b[j]);
					}
					else{
						a[j]=b[j-1]+b[j];
					}
					
				}
			
			}
		}
		result.push_back(a);
		b.assign(a.begin(), a.end());
	}
	vector<int>::iterator itBegin=a.begin();
	vector<int>::iterator itEnd=a.end();
	
	vector<vector<int> >::iterator itBegin2=result.begin();
	vector<vector<int> >::iterator itEnd2=result.end();  //用于测试现实，容器的遍历 
/*	while(itBegin!=itEnd)
	{
		cout<<*itBegin<<" ";
		itBegin++;
	}*/
	for(itBegin2;itBegin2!=itEnd2;itBegin2++)
	{
		for(vector<int>::iterator vit=(*itBegin2).begin();vit!=(*itBegin2).end();vit++)
		{
			cout<<*vit<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	test01(6);
}
