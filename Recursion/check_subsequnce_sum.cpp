#include <bits/stdc++.h>
    using namespace std;

bool printS(int index, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if(index==n)
    {
        if(sum==s)
            return true;

        return false;
    }

    s+=arr[index];
    ds.push_back(arr[index]);
    if(printS(index+1, ds, s, sum, arr, n))
        return true;

    
    s-=arr[index];
    ds.pop_back();


    if(printS(index+1, ds, s, sum, arr, n))
        return true;
    return false;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    if(printS(0, ds, 0, sum, arr, n))
    {
        for(auto i:ds)
            cout<<i<<"   ";
    }
    else
    {
        cout<<"No solutin exists.";
    }



    return 0;
}