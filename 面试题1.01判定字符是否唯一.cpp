#include<iostream>
#include<string> 
#include<cstdlib>
#include<vector>
using namespace std;
//思路就是我们对于一个字符串，一个从左往右，一个从右往左，如果他们返回的位置一直都是相同的那么就每个字符都是一样的，否则就说明他有两个一样嗯字符。 
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
 		cout<<"每个字符都是唯一的"; 
	 }
	 else
	 {
	 	cout<<"不唯一"; 
	 }
 }
