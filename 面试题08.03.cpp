#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Ч�ʲ��Ǻܸߣ�ʱ�临�Ӷ���O(n)��Ȼ��ֱ�ӱ���һ����Ϊ�Ҿ����ˣ���
//��������һ�����Ѿ�������ˣ���ʵ�����ö��ַ�����һ�� 
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
