#include<iostream>
using namespace std;
#include<string>
#include<vector> 
#include<algorithm>
//没啥技术含量 
int maxProduct(vector<int>& nums) 		
{
	sort(nums.begin(),nums.end(),greater<int>());
	
	return (nums[0]-1)*(nums[1]-1);
    }
int main()
{
	vector<int> num={3,4,5,2};
	cout<<maxProduct(num);
}
