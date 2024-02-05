#include <bits/stdc++.h>
    using namespace std;

int DNF_sort(vector<int> &arr)
{
    int low=0, mid=0, hi=arr.size()-1;

    while(mid<=hi)
    {
        if(arr[mid]==0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }

        else if(arr[mid]==1)
        {
            mid++;
        }

        else if(arr[mid]==2)
        {
            swap(arr[mid], arr[hi]);
            hi--;
        }
    }
}


int main()
{
    vector<int> arr = {0, 1, 2, 1 , 2, 0, 2 ,1, 0};

    DNF_sort(arr);

    for(int i:arr)
        cout<<i<<endl;

    return 0;
}