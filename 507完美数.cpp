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
	for(int i=2;i<sqrt(num);i++)  //����һ��Ч�ʵ����⣬һ��ʼ�ǳ�ʱ�ģ������������Ժ�Ͳ���ʱ�ˣ� ���ö�����ֻ��Ҫ���ž��� 
	{
		if(num%i==0)		
		{
			sum=sum+i;		//ֱ�Ӽ����������� 
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
