#include<iostream>
using namespace std;
#include<string>
#include<vector> 
#include<set>
//��ٷ���������ƣ�����set�����ԣ�ֻ�ܴ�ȡ��ͬ�ģ�
//Ȼ������������set�ڵ�һ�α����зֱ��ȡҪ��0���кź��кţ�
//�ڵڶ���ѭ���н���Ӧ��λ����0 
void setZeroes(vector<vector<int>>& matrix) {
	
		set<int> record;    //
		set<int> record2;
        for(int i=0;i<matrix.size();i++)
        {
        	for(int j=0;j<matrix[0].size();j++)
        	{
        		if(matrix[i][j]==0)
        		{
        			record.insert(i);
        			record2.insert(j);
				}
			}
		}
		set<int>::iterator it;
		for(it=record.begin();it!=record.end();it++)
		{	
		  for(int n=0;n<matrix[0].size();n++)  //�ѵ�ǰ����Ϊ0 
        			{
        				matrix[*it][n]=0;
					}
		}
		for(it=record2.begin();it!=record2.end();it++) //�ѵ�ǰ����Ϊ0 
		{	
		  for(int n=0;n<matrix.size();n++)  
        			{
        				matrix[n][*it]=0;
					}
		}
				
		for(int i=0;i<matrix.size();i++)
		{
			for(int j=0;j<matrix[0].size();j++)
			{
				cout<<matrix[i][j];
			}
			cout<<endl;
		}
    }
int main()
{
	vector<vector<int>> matrix={{0,1,2,0},{3,1,4,1},{1,1,1,1}};
	setZeroes(matrix);
}
