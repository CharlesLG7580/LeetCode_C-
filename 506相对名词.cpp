#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<map>
#include<string>
//˼·����������map��ԭ����λ�ü�¼����
//Ȼ���մӴ�С����
//�������Ժ����ã����������Ժ��num�����һ�������ģ�
//��ô��������map�ҵ�ԭ����λ�ã���result��Ӧλ����Ϊ��Ӧ�ľ��� 
vector<string> rank2(vector<int>& nums) 
{
	map<int,int> m;
	for(int i=0;i<nums.size();i++)
	{
		m.insert(pair<int,int>(nums[i],i));
	}
//	map<int,int>::iterator iter;
//	for(iter = m.begin(); iter != m.end(); iter++)  
     //  cout<<iter->first<<' '<<iter->second<<endl;  
	
	sort(nums.begin(), nums.end(), greater<int>());  //�����������������ǵ��������˳��� 
	vector<string> res;
	res.resize(nums.size());   //�����Ѿ�֪���˽������Ĵ�С 
	for(int i=0;i<nums.size();i++)
	{
		
		if(i==0)   //һ������ 
		{
			res[m[nums[i]]]="Gold Medal";
		}
		else if(i==1)
		{
			res[m[nums[i]]]="Silver Medal";
		}
		else if(i==2)
		{
			res[m[nums[i]]]="Bronze Medal";
		}
		else        //ʣ��Ĵ����������� 
		{
			res[m[nums[i]]]=to_string(i+1);
		}
		
	}	
	return res;
} 
int main()
{
	vector<int >num2={5,4,3,2,1};
	rank2(num2); 
	
}
