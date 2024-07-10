#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const ll INF = LLONG_MAX >> 1;

class Node {
public:
    int data;
    Node* next;
    Node(int n)
    {
        this->data = n;
        next = NULL;
    }
};


class mystack {
public:
    Node* head;
    int size;
    mystack()
    {
        head = NULL;
        size = 0;
    }
    void push(int x)
    {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        size++;
    }
    int peek()
    {
        return head==NULL?-1:head->data;
    }
    void pop()
    {
        if(!head)
            return;
        Node* ref = head;
        head = head->next;
        free(ref);
        size--;
    }
    int ssize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size==0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
    #endif

    //code
    mystack st;
    cout<<st.peek()<<endl;
    st.push(12);
    cout<<st.peek()<<endl;
    cout<<st.ssize();


    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}