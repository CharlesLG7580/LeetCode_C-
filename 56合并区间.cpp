#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
vector<vector<int>> merge(vector<vector<int>>& intervals)
 {
 	vector<vector<int>> new_arr;
 	sort(intervals.begin(),intervals.end());  //������Ҫ��������
	new_arr.push_back(intervals[0]);
	
	//Ȼ������������
	/*���������� merged �洢���յĴ𰸡�

	���ȣ����ǽ��б��е����䰴����˵���������Ȼ�����ǽ���һ��������� merged �����У�
     ����˳�����ο���֮���ÿ�����䣺�����ǰ�������˵������� merged �����һ���������
	 �˵�֮����ô���ǲ����غϣ����ǿ���ֱ�ӽ��������������� merged ��ĩβ��
	 ���������غϣ�������Ҫ�õ�ǰ������Ҷ˵�������� merged �����һ�������Ҷ˵㣬
	 ������Ϊ���ߵĽϴ�ֵ��*/


	int	j=0;
	for(int i=1;i<intervals.size();i++) 
		{
			if(intervals[i][0]>new_arr[j][1])
			{
				new_arr.push_back(intervals[i]);   
				j++;  //��������ʶ�ֱ��ע�������� 
			}
			else if(intervals[i][0]==new_arr[j][1])
			{
				new_arr[j][1]=intervals[i][1];
			}
			else if(intervals[i][0]<new_arr[j][1])
			{
				if(intervals[i][1]>new_arr[j][1])
				{ 
					new_arr[j][1]=intervals[i][1];
				}
			}
		}
	 for(int i=0;i<new_arr.size();i++)
	 {
	 	for(int j=0;j<new_arr[0].size();j++)
	 	{
	 	    cout<<new_arr[i][j];
		 }
	 }
	 return new_arr;
  }
  int main()
  {
  	vector<vector<int>> intervals={{1,3},{2,6},{8,10},{15,18}};
  	merge(intervals);
   } 
