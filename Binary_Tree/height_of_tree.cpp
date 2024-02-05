#include <iostream>
#include <queue>
#include <climits>
	using namespace std;
int res_dia=INT_MIN#include <iostream>
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

int height(Node* root)
{
	if(!root)
		return 0;
	return max(height(root->left), height(root->right))+1;
}

int main()
{
	Node* temp = NULL;

	//build tree
	Node* root = build_tree_levelorder(temp);

	level_order_traversal(root);

	cout<<"Height of tree is: "<<height(root);

	return 0;
};

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


int height(Node* root)
{
	if(!root)
		return 0;

	int lh=diameter(root->left);
	int rh=diameter(root->right);

	return max(lh, rh)+1;
}


int main()
{
	Node* temp = NULL;

	//build tree
	Node* root = build_tree_levelorder(temp);

	level_order_traversal(root);

	cout<<"Heigt of tree is: "<<height(root);

	return 0;
}