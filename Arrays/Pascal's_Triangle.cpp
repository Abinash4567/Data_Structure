#include <bits/stdc++.h>
    using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1;

vector<int> generateArray(int n)
{
    vector<int> arr;
    arr.push_back(1);

    int result = 1; 

    for(int i=1; i<n; i++)
    {
        result = result * (n-i);
        result = result / i;
        arr.push_back(result);
    }
    return arr;
}   


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>> ans;
    for(int i=1; i<=n; i++)
        ans.push_back(generateArray(i));

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}