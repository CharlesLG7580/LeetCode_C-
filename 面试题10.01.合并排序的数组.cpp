#include<iostream>
using namespace std;
#include<vector>
void merge(vector<int>& A, int m, vector<int>& B, int n)
{
	vector<int>C;
	int p = 0, k = 0;				//没啥意思弄两个指针，因为已经是排好序的了嘛就很好搞
	while (p<m&&k<n)
	{
		
		if (A[p] < B[k])
		{
			C.push_back(A[p]);
			p++;
		}
		else
		{
			C.push_back(B[k]);
			k++;
		}
	}
	if (p == m)
	{
		while (k < n)
		{
			C.push_back(B[k]);
			k++;
		}
	}
	else
	{
		while (p < m)
		{
			C.push_back(A[p]);
			p++;
		}
	}
	for (int i = 0; i < C.size(); i++)			//最后再替换一下
	{
		A[i] = C[i];
		cout << A[i];
	}
}
int main()
{
	vector<int>A = { 1,2,3,0,0,0 };
	vector<int>B = { 2,5,6 };
	int m = 3, n = 3;
	merge(A, 3, B, 3);
}