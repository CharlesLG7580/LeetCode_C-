#include<iostream>
using namespace std;
#include<string>
#include<vector>
//˼·���ǵ��ű�����Ȼ��
string reverseWords(string s) {
	string s1;
	string rs;
	vector<string> v;
	bool flag = true;
	int begin, end;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			begin = i;
			break;
		}
	}
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] != ' ')
		{
			end = i;
			break;
		}
	}
	for (int i = end; i >= begin; i--)
	{
		if (s[i] == ' ' && flag == false)
		{
			cout << s[i] << endl;
			v.push_back(s1);
			rs = rs + s1 + " ";
			s1 = "";
			flag = true;   //  ����û����Ч�Ҿͺ������벻ͨ��ԭ��д��˫�Ⱥ�
		}
		else if (s[i] != ' ')
		{
			flag = false;
			s1 = s[i] + s1;
		}

	}
	rs = rs + s1;
	v.push_back(s1);
	string fs;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "sdfs";
		fs = fs + v[i];
		if (i != v.size() - 1)
		{
			fs = fs + " ";
		}
	}

	return fs;
}
int main()
{
	string a = "the sky is blue";
	reverseWords(a);
}