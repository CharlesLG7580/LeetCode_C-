#include<iostream>
#include<vector>
using namespace std;

//���������飬һ�����������һ�����ż�� ��һ����Ž�� 
 //Ȼ���������Ϳ����� 
vector<int> test01(vector<int> &A)   //���&���ž���һ�����ÿ��Ա����ڴ����һЩ������ 
{
	vector<int> a,b,c;
	vector<int>::iterator itBegin=A.begin();
	vector<int>::iterator itEnd=A.end();
	while(itBegin!=itEnd)  //��ż���������ֿ� 
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
	for(int i=0;i<A.size();i++)   //��ѧϰ�������±����vector���� 
	{
		c.push_back(a.at(m));    
		c.push_back(b.at(m));
		m++;			//
		i++;			//����m��һ��push����������i���ñ���һ�������� 
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
