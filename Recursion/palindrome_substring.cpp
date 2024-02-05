#include <bits/stdc++.h>
    using namespace std;

bool is_palindrome(string str, int low, int end)
{
    while(low<end)
    {
        if(str[low]!=str[end])
            return false;
        low++;
        end--;
    }
    return true;
}

void solve(int index, string str, vector<string> out, vector<vector<string>> &ans)
{
    if(index==str.size())
    {
        ans.push_back(out);
        return;
    }

    for(int i=index;i<str.size();i++)
    {
        if(is_palindrome(str, index, i))
        {
            out.push_back(str.substr(index, i-index+1));
            solve(i+1, str, out, ans);
            out.pop_back();
        }
    }
}


int main()
{
    string str = "aaba";
    vector<string> out;
    vector<vector<string>> ans;

    solve(0, str, out, ans);

    for(auto it=ans.begin();it!=ans.end();it++)
    {
        for(auto it1=it->begin();it1!=it->end();it1++)
            cout<<*it1<<"  ";
        cout<<endl;
    }
    return 0;
}