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
	cout << "������" << c << "����һ���ڵ㣺";
	create(T->next);
}
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode* head=new ListNode;  //������ǻ���½ڵ�ķ�ʽ
	
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
ListNode* reverseList(ListNode* head)   //����һ����ת����Ĳ�������ת����ı�׼������������ջ
{
	stack<ListNode*>s;
	ListNode* new_head=new ListNode; 
	new_head->next = NULL;
	new_head->val = 0;
	ListNode *rp,*p;			//һ�����������������ͷָ��ȥ�����ģ�����һ����ͷָ��ĸ���һ���������½��Ľڵ�
	rp = new_head;    //��¼ͷ���
	while (head != NULL)
	{
		s.push(head);  //��ջûë��
		head = head->next;
	}

	while (!s.empty())    //����Ҳ����empty���ж����ջ�Ƿ�Ϊ��
	{
		p = new ListNode;				//�������һ����׼������������
		p->val = s.top()->val;
		p->next = NULL;
		rp->next = p;   //��ͷָ��ָ�����
		rp = p;			//Ȼ��������ջ
		s.pop();
	}
	
	cout << new_head->val;

	cout << "��ս���" << endl;
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