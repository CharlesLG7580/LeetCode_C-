#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
vector<vector<int>> merge(vector<vector<int>>& intervals)
 {
 	vector<vector<int>> new_arr;
 	sort(intervals.begin(),intervals.end());  //首先需要进行排序
	new_arr.push_back(intervals[0]);
	
	//然后遍历这个数组
	/*我们用数组 merged 存储最终的答案。

	首先，我们将列表中的区间按照左端点升序排序。然后我们将第一个区间加入 merged 数组中，
     并按顺序依次考虑之后的每个区间：如果当前区间的左端点在数组 merged 中最后一个区间的右
	 端点之后，那么它们不会重合，我们可以直接将这个区间加入数组 merged 的末尾；
	 否则，它们重合，我们需要用当前区间的右端点更新数组 merged 中最后一个区的右端点，
	 将其置为二者的较大值。*/


	int	j=0;
	for(int i=1;i<intervals.size();i++) 
		{
			if(intervals[i][0]>new_arr[j][1])
			{
				new_arr.push_back(intervals[i]);   
				j++;  //用两个标识分别标注两个数组 
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
