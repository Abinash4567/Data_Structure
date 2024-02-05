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


bool validate_BST(Node* root, int max, int min)
{
	if(!root)
		return true;
	
	if(root->data < max and root->data > min)
	{
		bool lefty  = validate_BST(root->left, root->data, min);
		bool righty  = validate_BST(root->right, max, root->data);
		return lefty and righty;	
	}
	else
	{
		return false;
	}
}



int main()
{
	Node* temp = NULL;

	//build tree
	Node* root = build_tree_levelorder(temp);

	//Level Order traversal
	cout<<"\nLevel Order Traversal:\n";
	level_order_traversal(root);


	if(validate_BST(root, INT_MAX, INT_MIN))
		cout<<"Given tree is Valid BST.";
	else
		cout<<"Given tree is not valid BST";

	return 0;
}