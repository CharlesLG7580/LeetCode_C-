#include<iostream>
#include<string> 
#include<cstdlib>
#include<vector>
using namespace std;
//˼·�������Ƕ���һ���ַ�����һ���������ң�һ����������������Ƿ��ص�λ��һֱ������ͬ����ô��ÿ���ַ�����һ���ģ������˵����������һ�����ַ��� 
bool test(string astr)
{
    for(int i=0; i<astr.size();i++){
        if(astr.find(astr[i])!=astr.rfind(astr[i])){
            return false;
        }
    }
        return true;
    }

 int main()
 {
 	string s="leetcode";
 	if(test(s))
 	{
 		cout<<"ÿ���ַ�����Ψһ��"; 
	 }
	 else
	 {
	 	cout<<"��Ψһ"; 
	 }
 }
