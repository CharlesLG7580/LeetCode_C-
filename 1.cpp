#include<iostream>
#include<string>
using namespace std;
 
//˼·������ת����ͳһ��ĸ���ַ��� 
bool isPalindrome(string s) 
{
	string str; 
	int j=s.size()-1;
	for(int i=0;i<s.size();i++)   //ת���ַ��� 
	{
		if(isalnum(s[i]))  //�ж�һ���ַ��Ƿ������ֻ�����ĸ 
		{
			str+=tolower(s[i]); //����д��ĸת��ΪСд 
		}
		
	}
	
	//�ж��Ƿ��ǻ���
	int len=str.length();
	for(int i=0;i<len/2;i++)
	{
		if(str[i]!=str[len-1-i])
		{
			return false;
		}
	 } 
	 return true;
}
int main()
{
	string s="A man ,a plan ,a canal: Panama";
	if(isPalindrome(s))
	{
		cout<<"yes"; 
	 } 
	 else{
	 	cout<<"false";
	 }
 } 
