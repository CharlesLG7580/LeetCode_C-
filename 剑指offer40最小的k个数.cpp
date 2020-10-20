#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
vector<int> sorr(vector<int> & arr,int k)
{
	vector<int> res;
	sort(arr.begin(),arr.end());  //´Ë´¦µÄÅÅĞò 
	for(int i=0;i<k;i++)
	{
		res.push_back(arr[i]);
	}
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i];
	}
	
} 
int main()
{
	vector<int> ar={0,1,2,1};
	int k=1;
	sorr(ar,k);
}
