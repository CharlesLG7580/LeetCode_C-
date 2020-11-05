#include<iostream>
using namespace std;
#include<vector>

vector<int> test(vector<int>&nums,int target)
{
	bool flag=false;
	vector<int> res;
	int rec=0; 
	for(int i=0;i<nums.size();i++)  //直接用一个bool就可以找出开始位置，然后用一个数记录位置只记录几次就好 
	{
		if(nums[i]==target)
		{
			rec=i;
			if(!flag)
			{
				flag=true;
				res.push_back(i);
			}	
		}
	}
	if(!flag)  //异常情况，如果不存在目标值 
	{
		res.push_back(-1);
		res.push_back(-1);
	}
	else{    //这个就是循环结束以后它记录的还是最后一个所以我们就可以 
		res.push_back(rec);
	}
	return res;
	
	
	
 } 
 int main()
 {
 	vector<int> nums={5,7,7,8,8,10};
 	int target=6;
 	test(nums,target);
 }
