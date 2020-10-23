#include<iostream>
using namespace std;
#include<vector> 
int find(int k)
{
	//先生成一个fib
	vector<int> arr;
	int a=1;
	int b=1;
	arr.push_back(1);
	arr.push_back(1);
	int c,count=0;
	while(1)
	{
		c=a+b;
		a=b;
		b=c;
		arr.push_back(c);
		if(c>k)
		{
			break;
		}
	 } 
	 
	 int remain=k;
	 bool end=false;
	 //然后开始求和
	 while(1)
	 {
	 	for(int i=0;i<arr.size();i++)
	 		if(arr[i]>remain)
	 		{
	 			remain=remain-arr[i-1];
	 			cout<<arr[i-1];
	 			break;
			 }
			 else if(arr[i]==remain)
			 {
			 	count++;
			 	end=true;
			 	break;
			 }
	 	if(end)
	 	{
	 		break;
		 }
	  } 
	 return count;
	
 } 
 int main()
 {
 	int k=19;
 	find(k);
 }
