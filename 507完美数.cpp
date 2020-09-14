#include<iostream>
using namespace std;
#include<vector>

bool test(int num)
{
		vector<int> m;
	int sum=1;
    if(num<4)
    {
        return false;
    }
	for(int i=2;i<sqrt(num);i++)  //这是一个效率的问题，一开始是超时的，但是这样做以后就不超时了， 不用都计算只需要根号就行 
	{
		if(num%i==0)		
		{
			sum=sum+i;		//直接加了两个因子 
            sum+=num/i;
			
		}
	 } 
	 if(sum==num)
	 {
	 	return true;
	 }
	 else
	 {
	 	return false;
	 }
	
 } 
 int main()
 {
 	cout<<test(28);
 }
