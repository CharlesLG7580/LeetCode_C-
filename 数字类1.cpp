#include<iostream>
#include<vector>
#include<algorithm>
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
vector<int> smallerNumbersThanCurrent(vector<int>& nums)  //1365�ж���С�ڵ�ǰ���ֵ����֣��Ż��ķ����Ҿ��ÿ���������
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
int missingNumber(vector<int>& nums)    //�����ֵ��Ż���Ҳ�������÷��ε�˼��
{
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != i)
		{
			return i;  //�����ƥ������ôֱ�ӷ��ؾͿ���	
		}
	}
	nums.size();	//��������������Ǿ�˵����ľ������һ��ֵ
}

int kthFactor(int n, int k) //1492 n�ĵ�k������  //����Ҳ���Ǹ����⣬�����㲻���е�
{
	vector<int> rs;
	for (int i = 1; i < n; i++)  //1�����е������ҳ���
	{
		if (n % i == 0)
		{
			rs.push_back(i);
		}
	}
	sort(rs.begin(), rs.end());  //2����
	for (int i = 0; i < rs.size(); i++)   //3�ҵ�k��  
	{
		if (i == k-1)   
		{
			return rs[i];
		}
	}
	return -1;  //������ӵĸ��������ͷ���-1

}
int main()
{
	vector<int>nums = { 1,2,3,4 };
	exchange(nums);
}