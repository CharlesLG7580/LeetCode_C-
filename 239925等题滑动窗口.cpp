#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
using namespace std;

vector<int> exchange(vector<int>& nums) //��ָ Offer 21. ��������˳��ʹ����λ��ż��ǰ��ֱ�ӱ�����ͨ����
{
	vector<int> rs;
	vector<int>rs1;
	for (int i = 0; i < nums.size(); i++)			
	{
		if (nums[i] % 2 != 0)			//������һ������
		{
			rs.push_back(nums[i]);
		}
		else rs1.push_back(nums[i]);		//ż����һ������
	}
	for (int i = 0; i < rs1.size(); i++)
	{   
		rs.push_back(rs1[i]);
	}
	return rs;
}
vector<int> smallerNumbersThanCurrent(vector<int>& nums)  //1365�ж���С�ڵ�ǰ���ֵ����֣��Ż��ķ����Ҿ��ÿ���������
{
	vector<int>rs;
	int count = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums.size(); j++)
		{
			if (nums[j] < nums[i])count++;
		}
		rs.push_back(count);
		count = 0;
	}
	return rs;
}
int missingNumber(vector<int>& nums)    //�����ֵ��Ż���Ҳ�������÷��ε�˼��
{
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != i)
		{
			return i;  //�����ƥ������ôֱ�ӷ��ؾͿ���	
		}
	}
	nums.size();	//��������������Ǿ�˵����ľ������һ��ֵ
}

int kthFactor(int n, int k) //1492 n�ĵ�k������  //����Ҳ���Ǹ����⣬�����㲻���е�
{
	vector<int> rs;
	for (int i = 1; i < n; i++)  //1�����е������ҳ���
	{
		if (n % i == 0)
		{
			rs.push_back(i);
		}
	}
	sort(rs.begin(), rs.end());  //2����
	for (int i = 0; i < rs.size(); i++)   //3�ҵ�k��  
	{
		if (i == k-1)   
		{
			return rs[i];
		}
	}
	return -1;  //������ӵĸ��������ͷ���-1

}
vector<int> printNumbers(int n)   //��ָoffer17�򵥣�
{
	vector<int>rs;
	int i = 1;
	while (i<pow(10,n))  
	{
		
		rs.push_back(i);
		i++;

	}
	return rs;
}
bool backspaceCompare(string S, string T)     //844�ȽϺ��˸���ַ���100%\
											  ��Ҫ��˼���������ջ����������˸����˵��ɾ�����������԰ѳ�ջ\
											 
{
	stack<char> q1;  //��ʼ������ջ�ֱ�洢�����ַ���
	stack<char>q2;
	for (int i = 0; i < S.size(); i++)   //��һ���ַ�������ջ��
	{
		if (S[i] == '#')
		{
			if (!q1.empty())			//������Ҫ�жϵĲ�Ȼ����ǿ�ջ���޷���ջ��
			q1.pop();
		}
		else
		{
			q1.push(S[i]);
		}
	}
	for (int i = 0; i < T.size(); i++)
	{
		if (T[i] == '#')
		{
			if (!q2.empty())
			q2.pop();   //����ɾ��  
		}
		else
		{
			q2.push(T[i]);
		}
	}
	if (q1.size() != q2.size())  //�������ջ��Ԫ����Ŀ��һ��ֱ�ӷ���false
	{
		return false;
	}
	while (!q1.empty()&&!q2.empty())
	{

		if (q1.top() != q2.top())   //�Ƚ�ջ��Ԫ�أ�
		{
			return false;
		}
		else
		{
			q1.pop();  //��ջҲ�ǳ�ջ��Ԫ��
			q2.pop();
		}

	}
	return true;
}
bool isLongPressedName(string name, string typed)   //925 ��������
{
	int m1 = 0;
	char target = name[0];
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < name.size(); i++)
	{
		if (name[i] == target)
		{
			count1++;
		}
		else
		{
			for (int j = 0; j < typed.size(); j++)
			{
				if (typed[i] == target)
				{
					count2++;
				}
				else
				{
					break;
				}
			}
		}
		
	}
	while (1)
	{

	}

}
vector<int> maxSlidingWindow(vector<int>& nums, int k)   //��ָoffer59-I j�������ڵ����ֵ
{
	
	vector<int>son;
	vector<int>rs;
	if (nums.empty())  //������һ���п�
	{
		return rs;
	}
	int big = 0;
	for (int i = 0; i < nums.size()-k+1; i++) //������Ҫ��+1����
	{
		big = nums[i];
		for (int j = i; j < i + k; j++)
		{
			if (nums[j] > big)
			{
				big = nums[j];
			}
			
		}
		rs.push_back(big);
	}
	return rs;
}
vector<int> maxSlidingWindow2(vector<int>& nums, int k)   //239�������ڵ����ֵ�����������ѣ��ύ����Ļᳬʱ���ص�������Ż�
{  //�뵽�ľ��ǣ�������ʵ����Ҫÿ�ζ��ȣ�ÿ������һ����ôǰ������ֵ�Ϳ�����**����λ�ã�k���йأ���

	vector<int>son;
	vector<int>rs;
	if (nums.empty())  //������һ���п�
	{
		return rs;
	}
	int big = 0;
	for (int i = 0; i < nums.size() - k + 1; i++) //������Ҫ��+1����
	{
		big = nums[i];
		for (int j = i; j < i + k; j++)
		{
			if (nums[j] > big)
			{
				big = nums[j];
			}

		}
		rs.push_back(big);
	}
	return rs;
}
vector<int> singleNumbers(vector<int>& nums)    
{
	map<int, int> m;
	map<int, int>::iterator it;
	vector<int> rs;
	for (int i = 0; i < nums.size(); i++)
	{
		m[nums[i]]++;
	}
	for (it = m.begin(); it != m.end(); it++)
	{
		if ((*it).second == 1)
		{
			rs.push_back((*it).first);
		}
	}
	return rs;

}
char firstUniqChar(string s)   //��һ��ֻ����һ�ε��ַ�
{
	map<char, int> m;
	for (int i = 0; i < s.size(); i++)   //������һ��map���洢���ֵ�Ƶ�Σ�Ȼ������ҵ�һ��Ƶ����1de 
	{
		m[s[i]]++;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (m[s[i]]== 1)
		{
			return s[i];
		}
	}
	return ' ';
}
int findMin(vector<int>& nums) {
	for (int i = 0; i < nums.size()-1; i++)
	{
		if (nums[i] > nums[i + 1])
			return nums[i + 1];
	}
	//return *min_element(nums.begin(), nums.end());
}
vector<int> shuffle(vector<int>& nums, int n)    //1470 ������������
{
	vector<int> rs;  //����n/2����
	for (int i = 0; i < nums.size() / 2; i++)
	{

		rs.push_back(nums[i]);
		rs.push_back(nums[i + nums.size() / 2]);
	}
	return rs;

}
int numIdenticalPairs(vector<int>& nums)   //������
{
	int count = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums.size(); j++)
		{
			if (nums[i] == nums[j] && i < j)
			{
				count++;
			}
		}
	}
	return count;
}
vector<int> findDisappearedNumbers(vector<int>& nums)  //448�ҵ�������������ʧ������5%�������Ż�
{
	map<int, int>m;
	vector<int>rs;
	for (int i = 0; i < nums.size(); i++)
	{
		m[nums[i]]++;
	}
	for (int i = 1; i <= nums.size(); i++)
	{
		if (m[i] == 0)
		{
			rs.push_back(i);
		}
	}
	return rs;
}
int numberOfSteps(int num)
{
	int count = 0;
	while (num != 0)
	{
		if (num % 2 == 0)
		{
			num = num / 2;
		}
		else
		{
			num = num - 1;
		}
		count++;
	}
	return count;

}
string reverseVowels(string s)   //345. ��ת�ַ����е�Ԫ����ĸ
{
	//���Ȱ������Ԫ����ĸ�ҳ�����Ȼ�������滻������˷�ת
	vector<char>rs;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
		{
			rs.push_back(s[i]);
		}
	}
	int index = rs.size() - 1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
		{
			s[i] = rs[index];
			index--;
		}
	}
	return s;
}
int missingNumber(vector<int>& nums)  //������ 17.04. ��ʧ������
{		//ֱ�ӱ����������������ң�5%
		//�Ż��ķ������ǿ�����������͹�ʽ�����Ӧ���Ƕ��٣�Ȼ����һ�����ڵĺͣ��������ȱ������
	sort(nums.begin(), nums.end());
	int i = 0;
	for (i = 0; i < nums.size(); i++)
	{
		if (i != nums[i])
		{
			return nums[i] - 1;
		}
	}
	return nums[i - 1] + 1;
}
bool canPlaceFlowers(vector<int>& flowerbed, int n)   //605. �ֻ�����
{//һ��������������Ҳ��û˭��
	int count = 0;
	int m = 0;
	for (int i = 0; i < flowerbed.size(); i++)
	{
		if (flowerbed[i] == 0)
		{
			count++;
			if (count == 3)  //��������������������Ȼ������һ����ʱָ�뵽������0������Ҫcount+1
			{
				m++;
				count = 1;
			}
			else if ((count == 2 && i == 1))  //�����ǶԸ�ǰ������0��
			{
				i = i - 1;  //Ӧ�û���һλ��Ϊ��һ�μ����ĵ�һ��0
				m++;
				count = 0;
			}
			else if ((count == 2 && i == flowerbed.size() - 1) || flowerbed.size() == 1)  //�����ǿ��Ǻ�������0�Լ�ֻ��һ��0de qkkl 
			{
				m++;
				count = 0;
			}
		}
		else {
			count = 0;
		}
	}
	if (m < n)   //m���Ǵ洢�����ֵĻ�����Ŀ
	{
		return false;
	}
	else
	{
		return true;
	}

}
int main()
{
	vector<int>nums = { 1,2,3,4 };
	exchange(nums);
}