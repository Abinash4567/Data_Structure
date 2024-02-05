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

void sum_largestbloodline(Node* root, int &maxsum, int &maxlen, int sum, int depth)
{
	if(!root)
	{
		if(depth>maxlen)
		{
			maxlen = depth;
			maxsum = sum;
		}
		else if(depth==maxlen)
		{
			maxsum=max(maxsum, sum);
		}


		return;
	}



	sum+=root->data;

	sum_largestbloodline(root->left, maxsum, maxlen, sum, depth+1);
	sum_largestbloodline(root->right, maxsum, maxlen, sum, depth+1);
}

int main()
{
	Node* temp = NULL;

	//build tree
	Node* root = build_tree_levelorder(temp);

	level_order_traversal(root);

	int maxsum = INT_MIN;
	int maxlen=0;
	sum_largestbloodline(root, maxsum, maxlen, 0, 0);

	cout<<"Maxsum with longest bloodline is:"<<maxsum;

	return 0;
}