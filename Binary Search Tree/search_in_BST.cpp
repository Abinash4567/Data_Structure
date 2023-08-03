#include <iostream>
#include <queue>
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

Node* build_tree_levelorder(Node* root)
{
	int data;
	// cout<<"Enter data for root: ";
	cin>>data;
	
	if(data==-1)
		return NULL;

	queue<Node*> que;
	root = new Node(data);
	que.push(root);

	while(!que.empty())
	{
		Node* temp = que.front();
		que.pop();

		// cout<<"Enter data for left node: "+temp->data<<endl;
		cin>>data;

		if(data!=-1)
		{
			temp->left = new Node(data);
			que.push(temp->left);
		}

		// cout<<"Enter data for right node: "+temp->data<<endl;
		cin>>data;

		if(data!=-1)
		{
			temp->right = new Node(data);
			que.push(temp->right);
		}
	}
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


bool search_BST_recurse(Node* root, int key)
{
	if(!root)
		return false;
	if(root->data == key)
	return true;

	if(key>root->data)
		return search_BST_recurse(root->right, key);
	else if(key<root->data)
		return search_BST_recurse(root->left, key);
}

bool search_BST_iterate(Node* root, int key)
{
	while(root)
	{
		if(root->data > key)
			root=root->left;
		else if(root->data < key)
			root=root->right;
		else if(root->data == key)
			return true;
	}
	return false;
}


int main()
{
	Node* temp = NULL;

	//build tree
	Node* root = build_tree_levelorder(temp);

	//Level Order traversal
	cout<<"\nLevel Order Traversal:\n";
	level_order_traversal(root);


	if(search_BST_recurse(root, 12))
		cout<<"12 was found";
	else
		cout<<"12 wan't found";

	cout<<endl;

	if(search_BST_iterate(root, 28))
		cout<<"28 was found";
	else
		cout<<"28 wan't found";

	
	return 0;
}