#include<iostream>
using namespace std;

int test(string date)
{
	int year=0;
	for(int i=0;i<4;i++)
	{
		year=year*10+(date[i]-'0');
	}
	bool flag=(year%4==0)?((year%100==0)?(year%400==0):true):false;  //闰年的条件
	int acumu[12]={0,31,59,90,120,151,181,212,243,273,304,334};    //月份天数 
	int month=(date[5]-'0')*10+(date[6]-'0');  //求月份   
	int day=(date[8]-'0')*10+(date[9]-'0');  //求多余的天 
	if(month<3) return acumu[month-1]+day;  //月份减一就行 
	else
	{
		return acumu[month-1]+day+flag;   //flag 为0或1 
	}
 }
 int main() 
 {
 	string date="2019-01-09";
	cout<<test(date); 
 }
