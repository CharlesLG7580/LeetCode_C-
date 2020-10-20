#include<iostream>
using namespace std;
#include<vector>
//思路就是找1和0的分界点，断一次就计数一次
// 
int find(vector<int>&nums)
{
	int sum;
	int count=0;
	for(int i=0;i<nums.size();i++)
	{
		cout<<count; 
		if(nums[i]==1)
		{
			sum++;
		}
		else 
		{
			if(sum>count)    //这里也得加 
			   count=sum;
			sum=0;
		}
		if(i+1==nums.size()&&nums[i]==1)  //这个是特殊情况的处理，当最后一个是1的时候需要计数一次 
		{
			
			if(sum>count)
			   count=sum;
		}
	}
	return count;
}
int main()
{
	vector<int> num={1,1,0,1} ;
	cout<<find(num);
}

