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

int KthSmallest(Node* root, int &key)
{
	if(!root)
		return -1;

	int lefty = KthSmallest(root->left, key);
		if(lefty!=-1)
			return lefty;
		key--;
		if(key==0)
			return root->data;

	return KthSmallest(root->right, key);
}





int main()
{
	Node* temp = NULL;

	//build tree
	Node* root = build_tree_levelorder(temp);

	//Level Order traversal
	cout<<"\nLevel Order Traversal:\n";
	level_order_traversal(root);

	int key = 4;
	cout<<"Fourth Smallest Number is: "<<KthSmallest(root, key);

\
	return 0;
}