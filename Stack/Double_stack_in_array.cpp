#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const ll INF = LLONG_MAX >> 1;

class myStack {
public:
    int *arr;
    int top1;
    int top2;
    int ssize;
    myStack(int n)
    {
        arr = new int[n];
        top1 = -1;
        top2 = n;
        ssize = n;
    }
    void push1(int n)
    {
        if(top1+1==top2)
            return;
        arr[++top1] = n;
    }
    void push2(int n)
    {
        if(top2-1==top1)
            return;
        arr[--top2] = n;
    }
    int peek1()
    {
        return top1==-1?-1:arr[top1];
    }
    int peek2()
    {
        return top2==ssize?-1:arr[top2];
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
    myStack s(5);
    cout<<s.peek1()<<endl;
    s.push1(12);
    s.push2(34);
    cout<<s.peek1()<<endl;
    cout<<s.peek2();




    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}