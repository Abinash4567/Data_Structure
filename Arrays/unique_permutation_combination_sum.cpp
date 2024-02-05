#include <bits/stdc++.h>
    using namespace std;

void solve(int index, vector<int> &arr, vector<vector<int>> &ans, vector<int> out, int target)
{
    if(target==0)
    {
        ans.push_back(out);
        return;
    }
    for(int i=index;i<arr.size();i++)
    {
        if(target<arr[index])
            break;
        if(i>index and arr[i]==arr[i-1])
            continue;

        out.push_back(arr[i]);
        solve(index+1, arr, ans, out, target-arr[i]);
        out.pop_back();
    }
}

int main()
{
    vector<int> arr = {10,1,2,7,6,1,5};
    vector<vector<int>> ans;
    vector<int> out;
    int target = 8;
    sort(arr.begin(), arr.end());

    solve(0, arr, ans, out, target);

    for(auto it=ans.begin();it!=ans.end();it++)
    {
        for(auto it1=it->begin();it1!=it->end();it1++)
            cout<<*it1<<"  ";
        cout<<endl;
    }
    return 0;
}