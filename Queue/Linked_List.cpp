#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const ll INF = LLONG_MAX >> 1;

class Node {
public:
    int data;
    Node* next;
    Node(int value)
    {
        this->data = value;
        next = NULL;
    }
};

class Queue {
public:
    Node* front, *rear;
    Queue()
    {
        front = rear = NULL;
    }

    void push(int value)
    {
        Node* newNode = new Node(value);

        if(!front)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = rear->next;
    }
    void pop()
    {
        if(!front)
            return;
        if(front == rear)
            front = rear = NULL;
        else
            front = front->next;
    }

    int start()
    {
        if(!front)
            return -1;
        else
            return front->data;
    }

    int backside()
    {
        if(!rear)
            return -1;
        else
            return rear->data;
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
    Queue que;
    que.push(12);
    que.push(13);
    que.pop();
    cout<<que.start();





    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}