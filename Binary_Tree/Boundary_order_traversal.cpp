#include <iostream>
#include <queue>
#include <stack>
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

void left_boundary(vector<int> &ans, Node* root)
{
	if(root)
	{
		if(root->left)
		{
			ans.push_back(root->data);
			left_boundary(ans, root->left);
		}
		else
		{
			ans.push_back(root->data);
			left_boundary(ans, root->right);
		}
	}
}

void right_boundary(vector<int> &ans, Node* root)
{
	if(root)
	{
		if(root->right)
		{
			ans.push_back(root->data);
			left_boundary(ans, root->right);
		}
		else
		{
			ans.push_back(root->data);
			left_boundary(ans, root->left);
		}
	}
}

void leaf_traverse(vector<int> &ans, Node* root)
{
	if(!root)
		return;
	leaf_traverse(ans, root->left);
	leaf_traverse(ans, root->right);

	if(root->left==NULL and root->right==NULL)
		ans.push_back(root->data);

}




int main()
{
	Node* temp = NULL;

	//build tree
	Node* root = build_tree_levelorder(temp);

	level_order_traversal(root);

	//Boundary Order Traversal
	vector<int> arr;
	left_boundary(arr, root);
	right_boundary(arr, root->right);
	leaf_traverse(arr, root);



	for(int i:arr)
		cout<<i<<"  ";




	return 0;
}