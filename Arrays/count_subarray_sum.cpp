#include <bits/stdc++.h>
    using namespace std;

int count_subarray_sum(vector<int> arr, int k)
{
    int sum=0;
    int count =0;
    unordered_map<int, int> check;
    check.insert({0, 1});

    for(int i=0; i<arr.size(); i++)
    {
        sum+=arr[i];
        int search = sum-k;

        if(check.find(search)!=check.end())
        {
            count+=check[search];

            auto it=check.find(search);
            it->second=check[search]+1;
        }
        else if(check.find(search)==check.end())
        {
            check.insert({sum, 1});
        }
    }

    return count;

}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 1, 1, 1, 4, 2, -3};

    cout<<count_subarray_sum(arr, 3);

    return 0;
}