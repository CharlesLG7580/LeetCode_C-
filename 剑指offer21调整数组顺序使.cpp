#include<iostream>
#include<vector>
using namespace std;

vector<int> exchange(vector<int>& nums) //剑指 Offer 21. 调整数组顺序使奇数位于偶数前面直接暴力就通过了
{
	vector<int> rs;
	vector<int>rs1;
	for (int i = 0; i < nums.size(); i++)			
	{
		if (nums[i] % 2 != 0)			//奇数放一个数组
		{
			rs.push_back(nums[i]);
		}
		else rs1.push_back(nums[i]);		//偶数放一个数组
	}
	for (int i = 0; i < rs1.size(); i++)
	{   
		rs.push_back(rs1[i]);
	}
	return rs;
}
int main()
{
	vector<int>nums = { 1,2,3,4 };
	exchange(nums);
}