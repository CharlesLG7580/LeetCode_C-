#include<iostream>
#include<vector>
#include<map>
using namespace std;
//思路就是把每一个数出现了多少次记录下来记录到map里然后再遍历map找最大的 
int test01(vector<int> &arr) 
{
	map<int,int>m;
	int flag=-1;
	int key;
	for(int i=0;i<arr.size();i++)   //
		m[arr.at(i)]++;			//记录这个值出现了多少次 
	
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++) //遍历的同时找最大的 
	{
		
			if(flag==-1)	//如果是第一次就需要给一个初始值，这里是为了找最大的 
			{
				flag=(*it).second;
				key=(*it).first;
			}
			else 
			{
				if((*it).second>flag)   //如果大于这个值就替换 
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


