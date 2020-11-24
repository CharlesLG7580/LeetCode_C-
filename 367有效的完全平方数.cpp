#include<iostream>
using namespace std;

 bool isPerfectSquare(int num) 
 {
 		long left=2;
        long right=num/2;
        long mid;
        if(num<2)
        {
            return true;
        }
        while(left<=right)
        {
            mid=(left+right)/2;
            if(mid*mid==num)
            {
                return true;
            }
            else if(mid*mid<num)
            {
                left=mid+1;
            }
            else 
            {
                right=mid-1;
            }
        }
        return false;
 	
        

    }

 int main()
 {
 	if(isPerfectSquare(16))
 	{
 		cout<<"yes";
	 }
  } 
