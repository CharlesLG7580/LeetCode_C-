#include<iostream>
using namespace std;
#include<algorithm>
#include<unordered_set> 
//C++ 11�г����������µĹ�������:unordered_set��unordered_map��
//���ڲ�ʵ����set��map���в�ͬ��set��map�ڲ�ʵ���ǻ���RB-Tree��
//��unordered_set��unordered_map�ڲ�ʵ���ǻ��ڹ�ϣ��(hashtable)��
//unordered_set��unordered_map�ڲ�ʵ�ֵĹ����ӿڴ�����ͬ��

//hash�����hash���Ժ�洢��hashֵ��Ӧ��λ�ã������ͻ�Ļ��Ϳ���������ַ����
//ֱ���ں�����ӾͿ����� 
#include<malloc.h> 
struct ListNode {
      int val;
      ListNode *next;
      
  };
ListNode* test01(ListNode *head)
{
	if(head==nullptr)  //�˴���nullptr��c++11�������,�������dev֧�ֵøı�����ѡ�� 
	{
		return head;
	}
	unordered_set<int> occurred={head->val} ;  //�ȴ���һ���� 
	ListNode* pos=head;
	
	while(pos->next!=nullptr)  //���β�������� 
	{
		ListNode* cur=pos->next;
		if(!occurred.count(cur->val))  //�������ȡһ�����val���ֵĴ��� 
		{						//�����0�� 
			occurred.insert(cur->val);  //ԭ�����ǲ��ı�� 
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
 	ListNode d={1,NULL};  //���ǹ�������ķ�����������Ƕ�Ӧ�Ĳ����� 
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

