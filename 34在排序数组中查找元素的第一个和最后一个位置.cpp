#include<iostream>
using namespace std;
#include<vector>

vector<int> test(vector<int>&nums,int target)
{
	bool flag=false;
	vector<int> res;
	int rec=0; 
	for(int i=0;i<nums.size();i++)  //ֱ����һ��bool�Ϳ����ҳ���ʼλ�ã�Ȼ����һ������¼λ��ֻ��¼���ξͺ� 
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
	if(!flag)  //�쳣��������������Ŀ��ֵ 
	{
		res.push_back(-1);
		res.push_back(-1);
	}
	else{    //�������ѭ�������Ժ�����¼�Ļ������һ���������ǾͿ��� 
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
