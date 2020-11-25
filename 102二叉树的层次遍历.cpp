#include<iostream>
using namespace std;
#include<queue>
struct TreeNode
{
	char val;
	TreeNode* left;
	TreeNode* right;
};   //�������಻ͬ�ĵط���Ҫ��һ��



void create(TreeNode*&T)
{
	char c;
	cin >> c;
	if (c == '/')
	{
		return;
	}
	T = new TreeNode;
	T->val = c;
	T->left = NULL;
	T->right = NULL;
	cout << "������" << c << "����ڵ㣺";
	create(T->left);
	cout << "������" << c << "���ҽڵ㣺";
	create(T->right);
}
void prior_order(TreeNode* T)	//����ʲô�ľͲ��������� �������
{
	if (T)			//��
	{
		cout << T->val << " ";
		prior_order(T->left);
		prior_order(T->right);
	}

}
void LayerOrder(TreeNode* T)			//��α���
{
	queue<TreeNode*> q;
	q.push(T);
	while (!q.empty())
	{
		TreeNode* w = q.front();		//ȡ������Ԫ��
		q.pop();
		cout << w->val << " ";
		if (w->left != NULL) q.push(w->left);
		if (w->right != NULL)	q.push(w->right);
	}
}
int main()
{
	TreeNode* T=new TreeNode;
	T = NULL;
	create(T);
	LayerOrder(T);
	prior_order(T);
}