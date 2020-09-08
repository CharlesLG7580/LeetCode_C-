#include<iostream>
#include<vector>
#include<map>
using namespace std;
//效率不是很高，时间复杂度是O(n)，然后直接遍历一遍因为找就行了，，
//但是我们一看到已经排序好了，其实可以用二分法更快一点 
int test01(vector<int> nums)
{
	bool flag=true;
	int res=-1;
	for(int i=0;i<nums.size();i++)
	{
		if(nums[i]==i)
		{
			if(flag)
			{
				res=i;
				flag=false;
			}
			else
			{	
				if(i<res)
				{
					res=i;
				}
				
			}
			
		}
	}
	return res;
	
 } 
 int main()
 {
 	vector<int> a={0, 2, 3, 4, 5};
 	cout<<test01(a);
 }
