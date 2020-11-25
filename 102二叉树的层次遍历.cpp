#include<iostream>
using namespace std;
#include<queue>
struct TreeNode
{
	char val;
	TreeNode* left;
	TreeNode* right;
};   //这是与类不同的地方需要加一个



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
	cout << "请输入" << c << "的左节点：";
	create(T->left);
	cout << "请输入" << c << "的右节点：";
	create(T->right);
}
void prior_order(TreeNode* T)	//遍历什么的就不用引用了 先序遍历
{
	if (T)			//根
	{
		cout << T->val << " ";
		prior_order(T->left);
		prior_order(T->right);
	}

}
void LayerOrder(TreeNode* T)			//层次遍历
{
	queue<TreeNode*> q;
	q.push(T);
	while (!q.empty())
	{
		TreeNode* w = q.front();		//取出队首元素
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