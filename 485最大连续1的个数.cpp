#include<iostream>
using namespace std;
#include<vector>
//˼·������1��0�ķֽ�㣬��һ�ξͼ���һ��
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
			if(sum>count)    //����Ҳ�ü� 
			   count=sum;
			sum=0;
		}
		if(i+1==nums.size()&&nums[i]==1)  //�������������Ĵ��������һ����1��ʱ����Ҫ����һ�� 
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

