#include <bits/stdc++.h>
    using namespace std;

int search_rotated(vector<int> arr, int target)
{
    int lo=0, hi=arr.size()-1;

    while(lo<=hi)
    {
        int mid = lo+(hi-lo)/2;

        if(arr[mid]==target)
            return mid;

        if(arr[mid]>=arr[lo])     //left half sorted
        {
            if(arr[mid]<target and arr[lo]<target)
            {
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        else
        {
            if(arr[mid]<target and arr[hi])
                lo=mid+1;
            else
                hi=mid-1;
        }
    }
    return -1;
}


int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int target = 4;

    cout<<search_rotated(arr, target);

    return 0;
}


