#include<iostream>
#include<vector>
#include<map>
using namespace std;
//˼·���ǰ�ÿһ���������˶��ٴμ�¼������¼��map��Ȼ���ٱ���map������ 
int test01(vector<int> &arr) 
{
	map<int,int>m;
	int flag=-1;
	for(int i=0;i<arr.size();i++)   //
		m[arr.at(i)]++;			//��¼���ֵ�����˶��ٴ� 
	
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++) //������ͬʱ������ 
	{
		if((*it).first==(*it).second)
		{	
			if(flag==-1)	//����ǵ�һ�ξ���Ҫ��һ����ʼֵ��������Ϊ�������� 
			{
				flag=(*it).first;
			}
			else 
			{
				if((*it).first>flag)   //����������ֵ���滻 
				{
					flag=(*it).first;
				}
			}
			
		 } 
	}
	return flag;
}
	
int main()
{
	vector<int> a={2,3,4};
	cout<<test01(a);
}

