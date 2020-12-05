#include<iostream>
using namespace std;
#include<queue>
#include<stack>
struct ListNode
{
	int val;
	ListNode* next;
}; 



void create(ListNode*& T)
{
	int c;
	cin >> c;
	if (c == 0)
	{
		return;
	}
	T = new ListNode;
	T->val = c;
	T->next = NULL;
	cout << "请输入" << c << "的下一个节点：";
	create(T->next);
}
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode* head=new ListNode;  //这个才是获得新节点的方式
	
	ListNode* t = head;
	ListNode* q=l1;
	ListNode* temp;
	while (l1 != NULL&&l2!=NULL)
	{
		ListNode* inser;
		if (l1->val <= l2->val)
		{
			head->val = l1->val;
			head->next = NULL;
			head = head->next;
			l1 = l1->next;
		}
		else
		{
			head->val = l2->val;
			head->next = NULL;
			head = head->next;
			l2 = l2->next;   
		}
	}
	if (l1== NULL&&l2!=NULL)
	{
		head->next = l2;
	}
	return t;

}
ListNode* reverseList(ListNode* head)   //这是一个翻转链表的操作，翻转链表的标准操作就是利用栈
{
	stack<ListNode*>s;
	ListNode* new_head=new ListNode; 
	new_head->next = NULL;
	new_head->val = 0;
	ListNode *rp,*p;			//一般就是这样，不会用头指针去操作的，所以一个是头指针的副本一个是我们新建的节点
	rp = new_head;    //记录头肩点
	while (head != NULL)
	{
		s.push(head);  //入栈没毛病
		head = head->next;
	}

	while (!s.empty())    //这里也是用empty来判断这个栈是否为空
	{
		p = new ListNode;				//这里就是一个标准的链表插入操作
		p->val = s.top()->val;
		p->next = NULL;
		rp->next = p;   //让头指针指向这个
		rp = p;			//然后再利用栈
		s.pop();
	}
	
	cout << new_head->val;

	cout << "出战完成" << endl;
	while (new_head!=NULL)
	{
		cout <<new_head->val;
		new_head = new_head->next;
		//rp = rp->next;
	}
	return new_head->next;
}

int main()
{
	ListNode* l;
	create(l);
	reverseList(l);
	ListNode* l2;
	create(l2);
	
	mergeTwoLists(l, l2);
	while (l != NULL)
	{
		cout << l->val<<" ";
		l = l->next;
	}
}