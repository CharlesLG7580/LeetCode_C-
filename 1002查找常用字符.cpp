#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
//���˼·���Ǳ��������Ƚ���һ��map����ȡ��һ���ַ�������ĸӳ�䣬Ȼ���Ҿ�Ҫ��ʼ�ҽ����ˣ�
// 
vector<string> test01(vector<string> & A)
{
	string s=A[0];
	vector<string> B;
	map<char,int> m1;
	for(int i=0;i<s.size();i++)
	{
		m1[s[i]]++;
	}
	int sum=0;
	for(int i=0;i<s.size();i++)   //���������һ���ַ��������һ����ĸc 
	{
		for(int j=1;j<A.size();j++) //Ȼ��Ӻ������ÿ���ַ��� 
		{	
			for(int m=0;m<A[j].size();m++)		//���Ǳ�����lock 
			{
				if(A[j][m]==s[i])		//�ж�һ���Ƿ��cһ�����һ����sum��¼+1 
				{
					sum++;
				}
			}
			if(sum!=0)		//��һ���ҵ�����һ���ģ��������һ��ʼmap���¼�ľ���Ҫ���������ҽ������������ٵ� 
			{				//�����һ����˵��û�н���   ����Ǿ���֮�� 
				if(m1[s[i]]>sum)
				{
					m1[s[i]]=sum;   //��Զȡ������С�� 
				}
				sum=0; 
			}
			else  //˵�������ĸ��û�н���ֱ�ӿ������������� 
			{
				m1[s[i]]=0; 	
			}
			
		}
	}
	int j=0;
	 for(map<char,int>::iterator it=m1.begin();it!=m1.end();it++) 
	 {
	 	for(int i=0;i<(*it).second;i++)
	 	{
	 		string b(1,(*it).first); //  ������Ϊ�������͵�ԭ������֮�� 
	 		B.push_back(b);
		 }
	 }
	 return B;
	
} 
 int main()
 {
 	vector<string> a= {"cool","lock","cook"};
 	test01(a);
 }

