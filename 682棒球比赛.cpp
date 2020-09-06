#include<iostream>
#include<vector>
#include<string>
#include<stack>   //这是栈的头文件 
using namespace std;
//思路就是在栈里只存放有效的，然后对应的操作利用栈的相关操作来实现 
int test01(vector<string> & ops)
{
	stack<int> s;      //初始化一个栈 ， 
	int score;
	int sum_score=0;
	
	for(int i=0;i<ops.size();i++)     
	{
		if(ops.at(i)=="D")			//前一轮有效 ，提取栈顶元素就行 
		{
			score=s.top();
			s.push(2*score);  
		}
		else if(ops.at(i)=="+")   //前两轮有效,可以先把栈顶记录然后出栈再记录，再进栈保持完整性 
		{
			int a=s.top();
			s.pop();
			int b=s.top();
			s.push(a);
			s.push(a+b);
		}
		else if(ops.at(i)=="C")  //前一轮无效，直接出栈 
		{
			s.pop();
		}
		else
		{
			s.push(stoi(ops[i]));
		}
		
	}
	while(!s.empty())
	{
		sum_score+=s.top();
		s.pop();
	}
	return sum_score;
	
} 
 int main()
 {
 	vector<string> a= {"5","2","C","D","+"};
 	cout<<test01(a);
 }
