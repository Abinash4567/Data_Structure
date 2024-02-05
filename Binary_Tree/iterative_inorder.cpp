#include <bits/stdc++.h>
    using namespace std;
class Node
{
public: 
    int data;
    Node* left;
    Node* right;
};

void iterative_inorder(Node* root)
{
    stack<Node*> st;
    Node* curr = root;

    while(curr==NULL or st.empty()==false)
    {
        while(curr)
        {
            st.push(surr->data);
            curr= curr->left;
        }

        curr = st.top();
        st.pop();
        cout<<curr->data;
        curr=curr->right;
    }
}

void iterative_preorder(Node* root)
{
    Node* curr = root;
    stack<Node*> st;
    st.push(curr);

    while(st.empty()==false)
    {
        while(curr)
        {
            cout<<curr->key;
            if(curr->right)
                st.push(curr->right);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
    }
}

int main()
{
    iterative_inorder(root);
    return 0;
}
