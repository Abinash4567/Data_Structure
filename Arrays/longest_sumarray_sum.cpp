#include <bits/stdc++.h>
    using namespace std;

int longest_subarray(vector<int> arr, int k)
{
    unordered_map<int, int> mapping;
    int sum=0;
    int len=INT_MIN;

    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];

        if(sum==k)
        {
            len=max(len, i+1);
        }
        else if(mapping.find(sum-k)!=mapping.end())
        {
            len=max(len, i-mapping[sum-k]);
        }
        else if(mapping.find(sum-k)==mapping.end())
        {
            mapping[sum]=i;
        }
    }

    return len;
}

int longest_subarray1(vector<int> arr, int k)
{
    int left=0, right=0;
    int sum=arr[0];
    int n=arr.size();
    int len=INT_MIN;

    while(right<n)
    {
        while(left<=right and sum>k)
        {
            sum-=arr[left];
            left++;;
        }

        if(sum==k)
        {
            len=max(len, right-left+1);
        }

        right++;

        if(right<n)
            sum+=arr[right];
    }
    return len;
}


int main()
{
    vector<int> arr1 = {1, 2, 4, 6, 8, 12};

    int ans = longest_subarray(arr1, 10);

    cout<<ans;

    return 0;
}