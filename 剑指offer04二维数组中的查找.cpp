#include<iostream>
using namespace std;
#include<vector> 

bool find(vector<vector<int>>& matrix, int target) 
{
	if(matrix.size() == 0) return false;  //[]1
	int col=matrix.size();
	int col_max=col;
	int row=matrix[0].size();
	 if(col==0||row==0)  //[[]] 1
    {
        return false;
    }
	for(int i=0;i<col;i++)    //这一步是做优化，因为每一行是递增的，我提前找出不需要的行，不过也可能增加时间 
		if(matrix[i][0]>target)
			{
				col_max=i-1;
				break;
				
			}
	for(int i=0;i<=col_max;i++)  //对每一行做二分查找 
	{
		int left=0;
		int right=row-1;
		int pos=(left+right)/2;   
		while(left<=right)
		{
			if(target>matrix[i][pos])
			{
				left=pos+1;
			}
			else if(target<matrix[i][pos])
			{
				right=pos-1;
			}
			else
			{
				return true;
			}
			pos=(left+right)/2;	
		}
	 } 
	 return false;
}
int main()
{
	vector<vector<int>> matr={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10, 13, 14, 17, 24},
  {18, 21, 23, 26, 30}};
	if(find(matr,20))
	{
		cout<<"yes";
	}
}
