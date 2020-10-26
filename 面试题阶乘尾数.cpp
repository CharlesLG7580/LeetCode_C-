#include<iostream>
using namespace std;

int cou(int n)
{
	int m;
	int count=0;
	for(int i=1;i<=n;i++)
	{
		m=i;
		while(m!=0&&m>=5)
		{
			if(m%5==0)
			{
				count++;
				m=m/5;
			}
			else{break;
			}
		}
	}
	return count;
	
 } 
 int main()
 {
 	int n=10;
 	cout<<cou(n);
 }
