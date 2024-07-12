#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const ll INF = LLONG_MAX >> 1;

class Queue {
public:
    int *arr;
    int front, rear;
    int size;

    Queue(int n)
    {
        arr = new int[n];
        front = rear = -1;
        size = n;
    }

    bool isEmpty()
    {
        if(front==-1)
            return true;
        return false;
    }

    bool isFull()
    {
        if( (rear+1) % size == front)
            return true;
        return false;
    }

    void push(int value)
    {
        if(isFull())
            return;
        if(isEmpty())
        {
            front = 0;
            rear = 0;
            arr[rear] = value; 
        }
        else
        {
            rear = (rear + 1 ) % size;
            arr[rear] = value;
        }
    }

    void pop()
    {
        if(isEmpty())
            return;
        if(front==rear)
        {
            front = rear = -1;
            return;
        }
        else
        {
            front = (front + 1) % size;
        }
    }

    int frontOne()
    {
        if(isEmpty())
            return -1;
        else
            return arr[front];
    }

    int back()
    {
        if(isEmpty())
            return -1;
        else
            return arr[rear];
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
    Queue que(5);
    que.push(5);
    que.push(10);
    cout<<que.frontOne()<<endl;
    cout<<que.back()<<endl;
    que.push(90);
    cout<<que.back()<<endl;



    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}