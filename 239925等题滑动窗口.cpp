#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
using namespace std;

vector<int> exchange(vector<int>& nums) //剑指 Offer 21. 调整数组顺序使奇数位于偶数前面直接暴力就通过了
{
	vector<int> rs;
	vector<int>rs1;
	for (int i = 0; i < nums.size(); i++)			
	{
		if (nums[i] % 2 != 0)			//奇数放一个数组
		{
			rs.push_back(nums[i]);
		}
		else rs1.push_back(nums[i]);		//偶数放一个数组
	}
	for (int i = 0; i < rs1.size(); i++)
	{   
		rs.push_back(rs1[i]);
	}
	return rs;
}
vector<int> smallerNumbersThanCurrent(vector<int>& nums)  //1365有多少小于当前数字的数字，优化的方法我觉得可以先排序
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
int missingNumber(vector<int>& nums)    //像这种的优化的也可以利用分治的思想
{
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != i)
		{
			return i;  //如果不匹配了那么直接返回就可以	
		}
	}
	nums.size();	//如果都运行完了那就说明差的就是最后一个值
}

int kthFactor(int n, int k) //1492 n的第k个因子  //这题也就是个简单题，根本算不上中等
{
	vector<int> rs;
	for (int i = 1; i < n; i++)  //1把所有的因子找出来
	{
		if (n % i == 0)
		{
			rs.push_back(i);
		}
	}
	sort(rs.begin(), rs.end());  //2排序
	for (int i = 0; i < rs.size(); i++)   //3找第k个  
	{
		if (i == k-1)   
		{
			return rs[i];
		}
	}
	return -1;  //如果因子的个数不够就返回-1

}
vector<int> printNumbers(int n)   //剑指offer17简单，
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
bool backspaceCompare(string S, string T)     //844比较含退格的字符串100%\
											  主要的思想就是利用栈，如果遇到退格符就说明删除东西，所以把出栈\
											 
{
	stack<char> q1;  //初始化两个栈分别存储两个字符串
	stack<char>q2;
	for (int i = 0; i < S.size(); i++)   //第一个字符串存入栈里
	{
		if (S[i] == '#')
		{
			if (!q1.empty())			//这里是要判断的不然如果是空栈是无法出栈的
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
			q2.pop();   //这是删除  
		}
		else
		{
			q2.push(T[i]);
		}
	}
	if (q1.size() != q2.size())  //如果两个栈的元素数目不一样直接返回false
	{
		return false;
	}
	while (!q1.empty()&&!q2.empty())
	{

		if (q1.top() != q2.top())   //比较栈顶元素，
		{
			return false;
		}
		else
		{
			q1.pop();  //出栈也是出栈顶元素
			q2.pop();
		}

	}
	return true;
}
bool isLongPressedName(string name, string typed)   //925 长按键入
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
vector<int> maxSlidingWindow(vector<int>& nums, int k)   //剑指offer59-I j滑动窗口的最大值
{
	
	vector<int>son;
	vector<int>rs;
	if (nums.empty())  //这里是一步判空
	{
		return rs;
	}
	int big = 0;
	for (int i = 0; i < nums.size()-k+1; i++) //这里需要做+1才能
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
vector<int> maxSlidingWindow2(vector<int>& nums, int k)   //239滑动窗口的最大值，这题是困难，提交上面的会超时，重点是如何优化
{  //想到的就是，我们其实不需要每次都比，每次新增一个那么前面的最大值就可以用**（与位置，k都有关）次

	vector<int>son;
	vector<int>rs;
	if (nums.empty())  //这里是一步判空
	{
		return rs;
	}
	int big = 0;
	for (int i = 0; i < nums.size() - k + 1; i++) //这里需要做+1才能
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
char firstUniqChar(string s)   //第一个只出现一次的字符
{
	map<char, int> m;
	for (int i = 0; i < s.size(); i++)   //利用了一个map来存储出现的频次，然后遍历找第一个频次是1de 
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
vector<int> shuffle(vector<int>& nums, int n)    //1470 重新排列数组
{
	vector<int> rs;  //遍历n/2就行
	for (int i = 0; i < nums.size() / 2; i++)
	{

		rs.push_back(nums[i]);
		rs.push_back(nums[i + nums.size() / 2]);
	}
	return rs;

}
int numIdenticalPairs(vector<int>& nums)   //好数对
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
vector<int> findDisappearedNumbers(vector<int>& nums)  //448找到所有数组中消失的数字5%还可以优化
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
string reverseVowels(string s)   //345. 反转字符串中的元音字母
{
	//首先按正序把元音字母找出来，然后按逆序替换就完成了翻转
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
int missingNumber(vector<int>& nums)  //面试题 17.04. 消失的数字
{		//直接暴力解了先排序再找，5%
		//优化的方法就是可以先利用求和公式求出来应该是多少，然后求一下现在的和，做差就是缺的数字
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
bool canPlaceFlowers(vector<int>& flowerbed, int n)   //605. 种花问题
{//一道简单题做成这样也是没谁了
	int count = 0;
	int m = 0;
	for (int i = 0; i < flowerbed.size(); i++)
	{
		if (flowerbed[i] == 0)
		{
			count++;
			if (count == 3)  //如果出现连续的三个零必然可以种一个此时指针到第三个0所以需要count+1
			{
				m++;
				count = 1;
			}
			else if ((count == 2 && i == 1))  //这里是对付前两个是0的
			{
				i = i - 1;  //应该回退一位作为下一次计数的第一个0
				m++;
				count = 0;
			}
			else if ((count == 2 && i == flowerbed.size() - 1) || flowerbed.size() == 1)  //这里是考虑后两个是0以及只有一个0de qkkl 
			{
				m++;
				count = 0;
			}
		}
		else {
			count = 0;
		}
	}
	if (m < n)   //m就是存储可以种的花的数目
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