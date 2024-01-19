#include <bits/stdc++.h>
    using namespace std;

class Node
{
public:
    int length;
    int index;
    int value;
    string path;

    Node(int l, int i, int v, string str)
    {
        length = l;
        index = i;
        value = v;
        path = str;
    }
};

void lis(vector<int> arr, int n, vector<int> &dp, int &omax, int &oind)
{
    for(int i=1; i<n; i++)
    {
        int maxi = 0;
        for(int j=0; j<i; j++)
        {
            if(arr[i] > arr[j] and dp[j] > maxi)
            {
                maxi = dp[j];
            }   
        }

        dp[i] = maxi + 1;
        if(dp[i] > omax)
        {
            omax = dp[i];
            oind = i;
        }
        
    }
}

int main()
{

    vector<int> arr = {10, 22, 42, 33, 21, 50, 41, 60, 80, 3};
    int n = arr.size();

    vector<int> dp(n, 0);
    dp[0]=1;
    int omax = 1, oind = 0;
    lis(arr, n, dp, omax, oind);

    // for(int i:dp)
    //     cout<<i<<"  ";
    // cout<<omax<<"  "<<oind;

    Node* nn = new Node(omax, oind, arr[oind], to_string(arr[oind]) + "->");

    queue<Node*> queue;
    queue.push(nn);

    while(!queue.empty())
    {
        Node* ff = queue.front();
        queue.pop();

        if(ff->length==1)
        {
            cout<<ff->path.substr(0, ff->path.size()-2)<<endl;
        }

        for(int i=0; i<ff->index; i++)
        {
            if(dp[i] == ff->length-1 and arr[i]<ff->value)
            {
                queue.push(new Node(dp[i], i, arr[i], ff->path + to_string(arr[i]) + "->"));
            }
        }
    }

    return 0;
}
