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
	cout<<"Enter data for root: ";
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

		cout<<"Enter data for left node: "+temp->data<<endl;
		cin>>data;

		if(data!=-1)
		{
			temp->left = new Node(data);
			que.push(temp->left);
		}

		cout<<"Enter data for right node: "+temp->data<<endl;
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

void inorder_traversal(Node* root)      //left    root    right
{
	if(!root)
		return;
	inorder_traversal(root->left);
	cout<<root->data<<"   ";
	inorder_traversal(root->right);
}


void preorder_traversal(Node* root)      //root   left    right
{
	if(!root)
		return;

	cout<<root->data<<"   ";
	inorder_traversal(root->left);
	inorder_traversal(root->right);
}

void post_traversal(Node* root)      //right    left    root
{
	if(!root)
		return;
	inorder_traversal(root->left);
	inorder_traversal(root->right);
	cout<<root->data<<"   ";
}



int main()
{
	Node* temp = NULL;

	//build tree
	Node* root = build_tree_levelorder(temp);

	//Level Order traversal
	cout<<"\nLevel Order Traversal:\n";
	level_order_traversal(root);

	//Inorder Traversal
	cout<<"\nInorder Traversal: ";
	inorder_traversal(root);

	//preorder Traversal
	cout<<"\nreorder Traversal: ";
	preorder_traversal(root);

	//postorder Traversal
	cout<<"\nPostorder Traversal: ";
	post_traversal(root);

	return 0;
}