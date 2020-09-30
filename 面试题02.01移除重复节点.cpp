#include<iostream>
using namespace std;
#include<algorithm>
#include<unordered_set> 
//C++ 11中出现了两种新的关联容器:unordered_set和unordered_map，
//其内部实现与set和map大有不同，set和map内部实现是基于RB-Tree，
//而unordered_set和unordered_map内部实现是基于哈希表(hashtable)，
//unordered_set和unordered_map内部实现的公共接口大致相同，

//hash表就是hash完以后存储到hash值对应的位置，如果冲突的话就可以用连地址法，
//直接在后面添加就可以了 
#include<malloc.h> 
struct ListNode {
      int val;
      ListNode *next;
      
  };
ListNode* test01(ListNode *head)
{
	if(head==nullptr)  //此处的nullptr是c++11新引入的,如果想让dev支持得改编译器选项 
	{
		return head;
	}
	unordered_set<int> occurred={head->val} ;  //先存入一个， 
	ListNode* pos=head;
	
	while(pos->next!=nullptr)  //依次操作后面的 
	{
		ListNode* cur=pos->next;
		if(!occurred.count(cur->val))  //这里就是取一下这个val出现的次数 
		{						//如果是0次 
			occurred.insert(cur->val);  //原链表是不改变的 
			pos=pos->next; 
		}
		else
		{
			pos->next=pos->next->next;
		}
	}
	pos->next=nullptr;
	return head;
}
 int main()
 {
 	ListNode d={1,NULL};  //这是构造链表的方法，里面就是对应的参数， 
 	ListNode c={1,&d};
 	ListNode b={3,&c};
 	ListNode a={2,&b};
 	ListNode *head=&a; 
 	head=test01(head); 
 	while(head!=nullptr)
 	{
 		cout<<head->val;
 		head=head->next;
	 }

 }

