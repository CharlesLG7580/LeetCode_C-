#include<iostream>
#include<vector>
#include<map>
using namespace std;
//˼·���ǰ�ÿһ���������˶��ٴμ�¼������¼��map��Ȼ���ٱ���map������ 
int test01(vector<int> &arr) 
{
	map<int,int>m;
	int flag=-1;
	int key;
	for(int i=0;i<arr.size();i++)   //
		m[arr.at(i)]++;			//��¼���ֵ�����˶��ٴ� 
	
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++) //������ͬʱ������ 
	{
		
			if(flag==-1)	//����ǵ�һ�ξ���Ҫ��һ����ʼֵ��������Ϊ�������� 
			{
				flag=(*it).second;
				key=(*it).first;
			}
			else 
			{
				if((*it).second>flag)   //����������ֵ���滻 
				{
					key=(*it).first;
					flag=(*it).second;
				}
			}
			
		 
	}
	return key;
}
	
int main()
{
	vector<int> a={2,2,2,3,4};
	cout<<test01(a);
}


