#include <iostream>
#include <queue>
#include <climits>
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

Node* build_BST(vector<int> &preorder, int &index, int min, int max)
{
	if(index>=preorder.size())
		return NULL;

	if(preorder[index] > max or preorder[index] < min)
		return NULL;

	Node* root = new Node(preorder[index++]);

	root->left = build_BST(preorder, index, min, root->data);
	root->right = build_BST(preorder, index, root->data, max);

	return root;
}





void level_order_traversal(Node* root)
{
	queue<Node*> que;
	que.push(root);

	while(!que.empty())
	{
		int n=que.size();
		for(int i=0;i<n;i++)
		{
			Node* temp = que.front();
			cout<<temp->data<<"  ";
			que.pop();

			if(temp->left!=NULL)
				que.push(temp->left);

			if(temp->right!=NULL)
				que.push(temp->right);
		}
		cout<<endl;
	}
}



int main()
{
	vector<int> preorder {20, 10, 5, 15, 13, 35, 30, 42};

	int index=0;
	Node* root = build_BST(preorder, index, INT_MIN, INT_MAX); 

	//Level Order traversal
	cout<<"\nLevel Order Traversal:\n";
	level_order_traversal(root);

	return 0;
}