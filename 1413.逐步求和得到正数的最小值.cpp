#include<iostream>
using namespace std;
#include<vector>

//ֱ�ӽ����ۼӣ�Ȼ���ҵ�����С�����Ǽ�¼һ�£�Ȼ����з�����������>=0ֱ�ӷ���1���У�
//��ԭ���ĸ�����Ϊ��Ȼ���1 
int test(vector<int> &nums)
{
	int sum=0,startValue,min_sum;
	for(int i=0;i<nums.size();i++)
	{
		sum=sum+nums.at(i);
		if(i==0)
		{
			min_sum=sum;
		}
		else
		{
			if(sum<min_sum)
			{
				min_sum=sum;
			}
		}
		
	}
    if(min_sum<0)
	{
		startValue=1-min_sum;
		return startValue;
	}
	else
		return 1;
		
}
int main()
{vector<int> nums;
	nums.push_back(-3);
	nums.push_back(2);
	nums.push_back(-3);
	cout<<test(nums);
}
