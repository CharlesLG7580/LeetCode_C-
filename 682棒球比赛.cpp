#include<iostream>
#include<vector>
#include<string>
#include<stack>   //����ջ��ͷ�ļ� 
using namespace std;
//˼·������ջ��ֻ�����Ч�ģ�Ȼ���Ӧ�Ĳ�������ջ����ز�����ʵ�� 
int test01(vector<string> & ops)
{
	stack<int> s;      //��ʼ��һ��ջ �� 
	int score;
	int sum_score=0;
	
	for(int i=0;i<ops.size();i++)     
	{
		if(ops.at(i)=="D")			//ǰһ����Ч ����ȡջ��Ԫ�ؾ��� 
		{
			score=s.top();
			s.push(2*score);  
		}
		else if(ops.at(i)=="+")   //ǰ������Ч,�����Ȱ�ջ����¼Ȼ���ջ�ټ�¼���ٽ�ջ���������� 
		{
			int a=s.top();
			s.pop();
			int b=s.top();
			s.push(a);
			s.push(a+b);
		}
		else if(ops.at(i)=="C")  //ǰһ����Ч��ֱ�ӳ�ջ 
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
