 #include <iostream>
#include <queue>
#include <stack>
#include <map>
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


void vertical_order(map<int, vector<int>> &map, Node* root, int hdis)
{
	if(!root)
		return;

	map[hdis].push_back(root->data);
	vertical_order(map, root->left, hdis-1);
	vertical_order(map, root->right, hdis+1);

}


int main()
{
	Node* temp = NULL;

	//build tree
	Node* root = build_tree_levelorder(temp);

	level_order_traversal(root);

	map<int, vector<int>> m;
	vertical_order(m, root, 0);

	// map<int, vector<int>>:: iterator it;

	cout<<"\n"<<"\n"<<"\n";

	
	for(auto it = m.begin(); it!= m.end(); it++)
	{
		cout<<it->first<<": ";
		for(int j=0; j<(it->second).size(); j++)
			cout<<(it->second)[j]<<"   ";

		cout<<endl;
	}


	return 0;
}