#include<iostream>
#include<vector>
using namespace std;

//�����ҵ����ɣ�ǰ���п�������ʼ�����ӵ����п�ʼ�������еĵڶ�������ʼÿһ����������һ�е������1+��ǰ���꣬���Ծ�ÿ��������
 //�͸���һ��b��Ϊ��һ�������µ�һ��a����������Ҫ����һЩ�߽����⣬�����һ�������һ������1����������Խ������ 
vector<int> test01(int rowIndex) 
{
	vector<int> a,b;
	a.push_back(1);  //��ʼ������1 
	vector<vector<int> > result;
	for(int i=0;i<rowIndex+1;i++)//���Ǵӵ�0�п�ʼ�� 
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
				else if(j==i)  //�߽����� 
				{
					a.push_back(1);
				}
				else
				{
					if(j>=a.size())  //�������Խ������ 
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
	vector<vector<int> >::iterator itEnd2=result.end();  //���ڲ�����ʵ�������ı��� 
/*	while(itBegin!=itEnd)
	{
		cout<<*itBegin<<" ";
		itBegin++;
	}*/
	vector<int> res;
	int m=0;
	for(itBegin2;itBegin2!=itEnd2;itBegin2++)
	{
		if(m==result.size()-1)
		{
		
		for(vector<int>::iterator vit=(*itBegin2).begin();vit!=(*itBegin2).end();vit++)
		{
			res.push_back(*vit);
			cout<<*vit<<" ";
		}
	}
		m++;
	}
	return res;
}
int main()
{
	vector<int> m;
	m=test01(6);
	for(int i=0;i<m.size();i++)
	{
		cout<<m.at(i);
	}
}

