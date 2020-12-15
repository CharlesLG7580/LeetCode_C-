#include<iostream>
#include<vector>
#include<algorithm>
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
vector<int> smallerNumbersThanCurrent(vector<int>& nums)  //1365有多少小于当前数字的数字，优化的方法我觉得可以先排序
{
	vector<int>rs;
	int count = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums.size(); j++)
		{
			if (nums[j] < nums[i])count++;
		}
		rs.push_back(count);
		count = 0;
	}
	return rs;
}
int missingNumber(vector<int>& nums)    //像这种的优化的也可以利用分治的思想
{
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != i)
		{
			return i;  //如果不匹配了那么直接返回就可以	
		}
	}
	nums.size();	//如果都运行完了那就说明差的就是最后一个值
}

int kthFactor(int n, int k) //1492 n的第k个因子  //这题也就是个简单题，根本算不上中等
{
	vector<int> rs;
	for (int i = 1; i < n; i++)  //1把所有的因子找出来
	{
		if (n % i == 0)
		{
			rs.push_back(i);
		}
	}
	sort(rs.begin(), rs.end());  //2排序
	for (int i = 0; i < rs.size(); i++)   //3找第k个  
	{
		if (i == k-1)   
		{
			return rs[i];
		}
	}
	return -1;  //如果因子的个数不够就返回-1

}
int main()
{
	vector<int>nums = { 1,2,3,4 };
	exchange(nums);
}