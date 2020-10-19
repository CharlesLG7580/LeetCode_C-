#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<map>
#include<string>
//思路就是先利用map将原来的位置记录下来
//然后按照从大到小排序，
//排序完以后利用，遍历排序以后的num比如第一个是最大的，
//那么我们利用map找到原来的位置，将result对应位置置为相应的就行 
vector<string> rank2(vector<int>& nums) 
{
	map<int,int> m;
	for(int i=0;i<nums.size();i++)
	{
		m.insert(pair<int,int>(nums[i],i));
	}
//	map<int,int>::iterator iter;
//	for(iter = m.begin(); iter != m.end(); iter++)  
     //  cout<<iter->first<<' '<<iter->second<<endl;  
	
	sort(nums.begin(), nums.end(), greater<int>());  //这个排序第三个参数是调整排序的顺序的 
	vector<string> res;
	res.resize(nums.size());   //我们已经知道了结果数组的大小 
	for(int i=0;i<nums.size();i++)
	{
		
		if(i==0)   //一次排序 
		{
			res[m[nums[i]]]="Gold Medal";
		}
		else if(i==1)
		{
			res[m[nums[i]]]="Silver Medal";
		}
		else if(i==2)
		{
			res[m[nums[i]]]="Bronze Medal";
		}
		else        //剩余的存起来就行了 
		{
			res[m[nums[i]]]=to_string(i+1);
		}
		
	}	
	return res;
} 
int main()
{
	vector<int >num2={5,4,3,2,1};
	rank2(num2); 
	
}
