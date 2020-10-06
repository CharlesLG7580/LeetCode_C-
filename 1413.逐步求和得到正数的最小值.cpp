#include<iostream>
using namespace std;
#include<vector>

//直接进行累加，然后找到和最小的我们记录一下，然后进行分析，如果这个>=0直接返回1就行，
//把原来的负数变为正然后加1 
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
