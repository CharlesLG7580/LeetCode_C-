#include<iostream>
using namespace std;

int test(string date)
{
	int year=0;
	for(int i=0;i<4;i++)
	{
		year=year*10+(date[i]-'0');
	}
	bool flag=(year%4==0)?((year%100==0)?(year%400==0):true):false;  //���������
	int acumu[12]={0,31,59,90,120,151,181,212,243,273,304,334};    //�·����� 
	int month=(date[5]-'0')*10+(date[6]-'0');  //���·�   
	int day=(date[8]-'0')*10+(date[9]-'0');  //�������� 
	if(month<3) return acumu[month-1]+day;  //�·ݼ�һ���� 
	else
	{
		return acumu[month-1]+day+flag;   //flag Ϊ0��1 
	}
 }
 int main() 
 {
 	string date="2019-01-09";
	cout<<test(date); 
 }
