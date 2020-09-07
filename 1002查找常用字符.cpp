#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
//这个思路就是暴力，首先建立一个map来存取第一个字符串的字母映射，然后我就要开始找交集了，
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
	for(int i=0;i<s.size();i++)   //这个遍历第一个字符串比如第一个字母c 
	{
		for(int j=1;j<A.size();j++) //然后从后面遍历每个字符串 
		{	
			for(int m=0;m<A[j].size();m++)		//这是遍历的lock 
			{
				if(A[j][m]==s[i])		//判断一下是否和c一样如果一样就sum记录+1 
				{
					sum++;
				}
			}
			if(sum!=0)		//看一下找到几个一样的，如果少了一开始map里记录的就需要更新我们找交集智能找最少的 
			{				//如果不一样，说明没有交集   这就是精妙之处 
				if(m1[s[i]]>sum)
				{
					m1[s[i]]=sum;   //永远取交集最小的 
				}
				sum=0; 
			}
			else  //说明这个字母就没有交集直接可以让他归零了 
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
	 		string b(1,(*it).first); //  这里因为参数类型的原因，无奈之举 
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

