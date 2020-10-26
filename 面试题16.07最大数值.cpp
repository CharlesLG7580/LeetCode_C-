#include<iostream>
using namespace std;
#include<stdint.h> 

int test01(int a,int b)
{
	uint64_t dif = (uint64_t)a - (uint64_t)b;
	cout<<(uint64_t)dif<<endl;
    int k = dif >> 63;
    cout<<k;
    return a*(k^1) + b*k;
	
 } 
 int main()
 {
 	int a=1,b=2;
 	test01(a,b);
 }
