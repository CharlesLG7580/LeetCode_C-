#include<iostream>
#include<vector>
using namespace std;

vector<int> exchange(vector<int>& nums) //��ָ Offer 21. ��������˳��ʹ����λ��ż��ǰ��ֱ�ӱ�����ͨ����
{
	vector<int> rs;
	vector<int>rs1;
	for (int i = 0; i < nums.size(); i++)			
	{
		if (nums[i] % 2 != 0)			//������һ������
		{
			rs.push_back(nums[i]);
		}
		else rs1.push_back(nums[i]);		//ż����һ������
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