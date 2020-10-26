#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int test(vector<int>&nums)
{
	int num=0;
	int max_num=0; 
	for(int i=0;i<nums.size();i++)
	{
		num=count(nums.begin(),nums.end(),nums[i]); 
		if(num>max_num)
		{
			max_num=num;
		}	
	}
	for(int i=0;i<nums.size();i++)
	{
		 
		
	}
	cout<<max_num;
	
}
int main()
{
	vector<int>a={1,2,2,3,1};
	test(a);
}
