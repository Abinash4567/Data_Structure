#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const ll INF = LLONG_MAX >> 1;

class Node {
public:
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head)
{
    while(head)
    {
        cout<<head->data<<"-->";
        head= head->next;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
    #endif

    //code
    Node* head = new Node(5);
    head->next = new Node(8);
    head->next->next = new Node(7);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(12);
    head->next->next->next->next->next = new Node(15);

    Node* curr = head->next->next;
    Node* prev = head;
    head = head->next;
    head->next = prev;

    while(curr and curr->next)
    {
        prev->next = curr->next;
        prev = curr;
        Node* newCurr = prev->next->next;
        prev->next->next = prev;
        curr = newCurr;
    }
    prev->next = curr;

    print(head);

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}