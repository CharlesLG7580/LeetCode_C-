#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

vector<vector<int>> permute(vector<int>&nums)
{
	//��һ��д�����������������
	
	//stl�п����ֱ���������е� 
	
	//����Ľ������ 
	sort(nums.begin(),nums.end());
	int size=nums.size();
	vector<vector<int>> ret;
	int count=0;
	while(1)  //���е���Ŀ 
	{
		count++ ;
		ret.push_back(nums); //������С��һ������Ҳ�ǵ�һ������ 
							 //Ȼ��������һ����������
		int accend=size-1;
		while(accend!=0 &&nums[accend-1]>nums[accend])
				accend-=1;
		cout<<"sdfas";
		if(accend==0)
			break;
		int mini=nums[accend-1];
		for(int i=size-1;i>=accend;i--)
			if(nums[i]>mini)
			{
				swap(nums[i],nums[accend-1]);
				break;
			}
		for(int i=accend,j=size-1;i<=j;i++,j--)
			swap(nums[i],nums[j]);
	 } 
	 cout<<count<<endl;
	 return ret;	
}
int main()
{
	vector<int> a={1,2,3};
	 vector<vector<int>> b=permute(a);
	 for(int i=0;i<b.size();i++)
	 	{
		 for(int j=0;j<b[0].size();j++)
	 	{
	 		cout<<b[i][j];
		 }
		 cout<<endl;
		}
}
