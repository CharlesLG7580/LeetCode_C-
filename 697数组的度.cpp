#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<algorithm>
#include<map>
int test(vector<int>&nums)
{
	int num=0;
	int max_num=0; 
	int max_ele=nums[0];
	map<int,int> m;
	for(int i=0;i<nums.size();i++)		//���Ƚ�Ƶ����¼��һ��map�� 
	{
		m[nums[i]]++;
	}
	map<int,int>::iterator mt=m.begin();
	while(mt!=m.end())   //Ȼ��������map�����Ƶ�� 
	{
		if((*mt).second>max_num)
			max_num=(*mt).second;   
		mt++;
	}
	set<int> son;  			//set�����Բ����ظ���Ԫ�أ����һ��Զ����� 
	set<int>::iterator it;
	mt=m.begin();
	while(mt!=m.end())		//Ȼ���ҳ�Ƶ���������е��� 
	{
	
		if((*mt).second==max_num) 
		{
			son.insert((*mt).first); 
		}
		mt++;
	}
	
	
	int count=0;
	int du=0;
	int min_count=50000;
	bool flag=false;
	for(it=son.begin();it!=son.end();it++)  //Ȼ����������������Ƶ����set Ȼ����������������� 
	{
		max_ele=*it;
		for(int i=0;i<nums.size();i++)
		{
			if(nums[i]==max_ele)  //��̵Ŀ϶���һ������������������������ҵ���Ȼ��ͳ�� 
			{
				du++;   //���ǲ��ҵı�׼������ﵽ�˾Ϳ���ֹͣ�� 
				flag=true;
				count++;		//count��¼���� 
				if(du==max_num)
				{
					break;
				}
			}
			else if(flag==true)			//������ǿ��ǰ���������̴�������������� 
			{
				count++;
			}
		}
		if(count<min_count)
		{
			min_count=count;
		}
		flag=false;
		count=0;
		du=0; 
	}
	return min_count;
	
}
int main()
{
	vector<int>a={1,2,2,3,1,4,2};
	cout<<test(a);
}
