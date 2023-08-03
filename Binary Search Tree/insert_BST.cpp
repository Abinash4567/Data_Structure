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

Node* insert_BST_recurse(Node* root, int key)
{
	if(! root)
		return new Node(key);

	else if (key > root->data)
		root->right = insert_BST_recurse(root->right, key);
	else if (key < root->data)
		root->left = insert_BST_recurse(root->left, key);
	return root;
}

Node* insert_BST_iterative(Node* root, int key)
{
	Node* curr = root;
	Node* parent = NULL;

	while(curr)
	{
		parent = curr;

		if(key > root->data)
			curr=curr->right;
		else if(key<root->data)
			curr=curr->left;
		else
			return root;   // Value already present in tree
	}

	if(!parent)
		return new Node(key);
	else if(parent->data<key)
		parent->right = new Node(key);
	else 
		parent->left = new Node(key);

	return root; 
}




int main()
{
	Node* temp = NULL;

	//build tree
	Node* root = build_tree_levelorder(temp);

	//Level Order traversal
	cout<<"\nLevel Order Traversal:\n";
	level_order_traversal(root);

	root = insert_BST_recurse(root, 2);

	cout<<endl<<"After inserting 2"<<endl;
	level_order_traversal(root);

	cout<<"After inserting 50"<<endl;
	root = insert_BST_iterative(root, 50);
	level_order_traversal(root);


	return 0;
}