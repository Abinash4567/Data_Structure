#include <bits/stdc++.h>
    using namespace std;

int longest_subsequence(vector<int> arr)
{
    if(arr.size()==0)
        return 0;
    int len=1;

    unordered_set<int> st;

    for(int i:arr)
        st.insert(i);

    for(int i:arr)
    {
        if(st.find(i-1)==st.end())
        {
            int count = 1;
            int x=i;

            while(st.find(x+1)!=st.end())
            {
                count++;
                x++;
            }

            len = max(len, count);
        }
    }

    return len;

}

int main()
{
    vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};

    cout<<longest_subsequence(arr);


    return 0;
}