#include <iostream>
#include <queue>
#include <map>
	using namespace std;

class Node
{
	public:
	int data;
	Node* left; 
	Node* right;

	Node(int value)
	{
		data = value;
		left = NULL;
		right = NULL;
	}
};

Node* build_tree_in_pre(vector<int> in, vector<int> pre, int n, map<int, int> pos, int &prestart, int instart, int inend)
{
	if(prestart>=n or instart>inend)
		return NULL;

	int element = pre[prestart++];
	int posi = pos[element];
	Node* temp = new Node(element);

	temp->left = build_tree_in_pre(in, pre, n, pos, prestart, instart, posi-1);
	temp->right = build_tree_in_pre(in, pre, n, pos, prestart, posi+1, inend);

	return temp;
}

void level_order(Node* root)
{
	if(!root)
		return;

	queue<Node*> que;

	que.push(root);

	while(!que.empty())
	{
		int n = que.size();

		for(int i=0;i<n;i++)
		{
			Node* temp = que.front();
			que.pop();
			cout<<temp->data<<"  ";

			if(temp->left)
				que.push(temp->left);

			if(temp->right)
				que.push(temp->right);
		}
		cout<<endl;
	} 
}


int main()
{
	Node* temp = NULL;

	vector<int> inorder {3, 1, 4, 0, 5, 2};
	vector<int> preorder {0, 1, 3, 4, 2, 5};
	int n = inorder.size();

	map<int, int> pos;
	for(int i=0;i<inorder.size();i++)
		pos[inorder[i]]=i;

	int prestart=0;
	Node* root = build_tree_in_pre(inorder, preorder, n, pos, prestart, 0, n-1);

	level_order(root);

	return 0;
}