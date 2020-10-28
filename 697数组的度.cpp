#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<algorithm>
#include<map>
int test(vector<int>&nums)
{
	int num=0;
	int max_num=0; 
	int max_ele=nums[0];
	map<int,int> m;
	for(int i=0;i<nums.size();i++)		//首先将频数记录到一个map里 
	{
		m[nums[i]]++;
	}
	map<int,int>::iterator mt=m.begin();
	while(mt!=m.end())   //然后遍历这个map找最大频数 
	{
		if((*mt).second>max_num)
			max_num=(*mt).second;   
		mt++;
	}
	set<int> son;  			//set不可以插入重复的元素，而且会自动排序 
	set<int>::iterator it;
	mt=m.begin();
	while(mt!=m.end())		//然后找出频数最大的所有的数 
	{
	
		if((*mt).second==max_num) 
		{
			son.insert((*mt).first); 
		}
		mt++;
	}
	
	
	int count=0;
	int du=0;
	int min_count=50000;
	bool flag=false;
	for(it=son.begin();it!=son.end();it++)  //然后遍历这个存放了最大频数的set 然后找最短连续子数组 
	{
		max_ele=*it;
		for(int i=0;i<nums.size();i++)
		{
			if(nums[i]==max_ele)  //最短的肯定第一个就是这个数，所以我们先找到，然后统计 
			{
				du++;   //度是查找的标准，如果达到了就可以停止了 
				flag=true;
				count++;		//count记录长度 
				if(du==max_num)
				{
					break;
				}
			}
			else if(flag==true)			//这里就是考虑包含其它最短串里包含其它的数 
			{
				count++;
			}
		}
		if(count<min_count)
		{
			min_count=count;
		}
		flag=false;
		count=0;
		du=0; 
	}
	return min_count;
	
}
int main()
{
	vector<int>a={1,2,2,3,1,4,2};
	cout<<test(a);
}
