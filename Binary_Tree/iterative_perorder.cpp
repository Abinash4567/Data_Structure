#include <bits/stdc++.h>
    using namespace std;
class Node
{
public: 
    int data;
    Node* left;
    Node* right;
};

void iterative_preorder(Node* root)
{
    stack<Node*> st;
    Node* curr = root;
    st.push(curr);
    while(st.empty()==false)
    {
        curr = st.top();
        cout<<curr->data;
        st.pop();

        if(curr->right)
            st.push(curr->right);
        if(curr->right)
            st.push(curr->left);
    }
}

int main()
{
    iterative_inorder(root);
    return 0;
}
