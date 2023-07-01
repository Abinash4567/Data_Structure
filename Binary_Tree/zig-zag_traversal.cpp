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


vector<int> zig_zag(Node* root)
{
	vector<int> ans;
	if(!root)
		return ans;

	queue<Node*> que;
	stack<int> st;
	que.push(root);
	bool flag = true;

	while(!que.empty())
	{

		int n = que.size();
		for(int i=0;i<n;i++)
		{
			Node* temp = que.front();
			que.pop();
			
			if(flag)
			{
				ans.push_back(temp->data);
			}
			else
			{
				st.push(temp->data);
			}

			if(temp->left)
				que.push(temp->left);
			if(temp->right)
				que.push(temp->right);
		}

			if(!flag)
			{
				while(!st.empty())
				{
					ans.push_back(st.top());
					st.pop();
				}
			}
		flag=!flag;
	}

	return ans;
}


int main()
{
	Node* temp = NULL;

	//build tree
	Node* root = build_tree_levelorder(temp);

	level_order_traversal(root);

	vector<int> arr = zig_zag(root);

	for(auto i:arr)
		cout<<i<<"   ";



	return 0;
}