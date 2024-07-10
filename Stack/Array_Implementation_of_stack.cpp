#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const ll INF = LLONG_MAX >> 1;

class mstack {
public:
    int *arr;
    int top = -1;
    mstack(int n){
        arr = new int[n];
    }
    int peek(){
        return top==-1?-1:arr[top];
    }
    void push(int x){
        arr[++top] = x;
    }
    int size(){
        return top+1;
    }
    bool isEmpty(){
        return top==-1;
    }
    int pop(){
        return top==-1?-1:arr[top--];
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
    mstack st(5);
    st.push(12);
    st.push(13);
    st.push(90);
    st.push(45);

    while(!st.isEmpty())
    {
        cout<<st.peek()<<endl;
        st.pop();
    }


    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}