#include<iostream>
#include<string>
using namespace std;
 
//思路就是先转换成统一字母的字符串 
bool isPalindrome(string s) 
{
	string str; 
	int j=s.size()-1;
	for(int i=0;i<s.size();i++)   //转换字符串 
	{
		if(isalnum(s[i]))  //判断一个字符是否是数字或者字母 
		{
			str+=tolower(s[i]); //将大写字母转换为小写 
		}
		
	}
	
	//判断是否是回文
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
