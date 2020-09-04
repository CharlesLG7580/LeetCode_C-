#include<iostream>
#include<vector>
#include<map>
using namespace std;
//思路就是把每一个数出现了多少次记录下来记录到map里然后再遍历map就行了 
int test01(vector<int> &arr) 
{
	map<int,int>m;
	int flag=-1;
	for(int i=0;i<arr.size();i++)   //
		m[arr.at(i)]++;			//记录这个值出现了多少次 
	
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++) //遍历的同时找最大的 
	{
		if((*it).first==(*it).second)
		{	
			if(flag==-1)	//如果是第一次就需要给一个初始值，这里是为了找最大的 
			{
				flag=(*it).first;
			}
			else 
			{
				if((*it).first>flag)   //如果大于这个值就替换 
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

