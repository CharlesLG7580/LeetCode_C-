#include<iostream>
using namespace std;
#include<vector>

vector<int> runningSum(vector<int>& nums) 
{
	vector<int>rs;
	int r_sum = 0;
	/*for (int i = 0; i < nums.size(); i++)//δ�Ż��ı�����9%
		for (int j = 0; j <= i; j++)
		{
			r_sum = r_sum + nums[j];
		}
		rs.push_back(r_sum);
		r_sum = 0;
	}
	*/
	for (int i = 0; i < nums.size(); i++)  //�Ż��Ժ�41%
	{
		r_sum = r_sum + nums[i];
		rs.push_back(r_sum);
	}
	return rs;
	

}
int main()
{

}