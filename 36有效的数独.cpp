#include<iostream>
#include<vector>
#include<map> 
using namespace std;

bool test(vector<vector<char>>& board) 
{
	//���ֻ�ܳ���һ�ξ�������map������
	//Ȼ������������������Ϳ�����
	 map<char,int> m;
	 //��һ������ÿһ����û���ظ��� 
	 for(int i=0;i<9;i++)
	 {
	 	for(int j=0;j<9;j++)
	 	{
	 		m[board[i][j]]++;
	 		if(board[i][j]!='.') //�����ǵ� 
	 		{
			 
	 		if(m[board[i][j]]>1)   //�����������1˵���ظ��� 
	 		{
	 			cout<<board[i][j];
	 			return false;
			 }
			}
		 }
		 m.erase(m.begin(),m.end());	//��һ������Ͳ�Ӱ����һ�еĴ����� 
	  } 
	  
	  /******���н����Ų�******/ 
	  for(int i=0;i<9;i++)
	 {
	 	for(int j=0;j<9;j++)
	 	{
	 		m[board[j][i]]++;
	 		if(board[j][i]!='.')   //�������ǿո� 
	 		{
	 			if(m[board[j][i]]>1)
	 			{
	 				cout<<board[j][i];
	 				return false;
			 	}
			 }
		 }
		 m.erase(m.begin(),m.end());	  //��erase�����Ԫ�� 
	  } 
	  cout<<"fdsa";
	  /****�����Ÿ�С����******/
	  int i=0;
	  while(i<9)
	  {
	  	for(int count=0;count<9;)
	  	{
		 
	  	for(int s=i;s<i+3;s++)
	  	{
	  		for(int t=count;t<count+3;t++)
	  		{
	  			m[board[s][t]]++;
	 		if(board[s][t]!='.')   //�������ǿո� 
	 		{
	 			if(m[board[s][t]]>1)
	 			{
	 				cout<<s<<t<<board[s][t];
	 				return false;
			 	}
			 }
	  			
			  }
		  }
		  count=count+3;
		  m.erase(m.begin(),m.end());
	    }
	    i=i+3;
	  }
	  return true;
	
}
int main()
{
//	vector<vector<int>> te={{1,2,3},{2,3,4} };  //�˾����ͨ�����룬���Ƕ�άvector�ĳ�ʼ�� 
	vector<vector<char> > board={
								{'.','9','.','.','4','.','.','.','.'},
								{'1','.','.','.','.','.','6','.','.'},
								{'.','.','3','.','.','.','.','.','.'},
								{'.','.','.','.','.','.','.','.','.'},
								{'.','.','.','7','.','.','.','.','.'},
								{'3','.','.','.','5','.','.','.','.'},
								{'.','.','7','.','.','4','.','.','.'},
								{'.','.','.','.','.','.','.','.','.'},
								{'.','.','.','.','7','.','.','.','.'}
								};//˫���ź͵����ŵ����� 
	if(!test(board))
	{
		cout<<"NO";
	}
}
