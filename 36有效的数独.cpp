#include<iostream>
#include<vector>
#include<map> 
using namespace std;

bool test(vector<vector<char>>& board) 
{
	//解决只能出现一次就是利用map来计数
	//然后按他的三条规则遍历就可以了
	 map<char,int> m;
	 //第一步遍历每一行有没有重复的 
	 for(int i=0;i<9;i++)
	 {
	 	for(int j=0;j<9;j++)
	 	{
	 		m[board[i][j]]++;
	 		if(board[i][j]!='.') //不考虑点 
	 		{
			 
	 		if(m[board[i][j]]>1)   //如果计数超过1说明重复了 
	 		{
	 			cout<<board[i][j];
	 			return false;
			 }
			}
		 }
		 m.erase(m.begin(),m.end());	//做一下清除就不影响下一行的处理了 
	  } 
	  
	  /******对列进行排查******/ 
	  for(int i=0;i<9;i++)
	 {
	 	for(int j=0;j<9;j++)
	 	{
	 		m[board[j][i]]++;
	 		if(board[j][i]!='.')   //点代表的是空格 
	 		{
	 			if(m[board[j][i]]>1)
	 			{
	 				cout<<board[j][i];
	 				return false;
			 	}
			 }
		 }
		 m.erase(m.begin(),m.end());	  //用erase来清除元素 
	  } 
	  cout<<"fdsa";
	  /****遍历九个小方块******/
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
	 		if(board[s][t]!='.')   //点代表的是空格 
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
//	vector<vector<int>> te={{1,2,3},{2,3,4} };  //此句可以通过编译，就是二维vector的初始化 
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
								};//双引号和单引号的区别 
	if(!test(board))
	{
		cout<<"NO";
	}
}
