#include <bits/stdc++.h>
    using namespace std;

void printS(int index, vector<int> ds, int s, int sum, int arr[], int n)
{
    if(index==n)
    {
        if(sum==s)
        {
            for(auto i:ds)
                cout<<i<<"  ";
            cout<<endl<<endl;
        }
        return;
    }
    s+=arr[index];
    ds.push_back(arr[index]);
    printS(index+1, ds, s, sum, arr, n);

    
    s-=arr[index];
    ds.pop_back();
    printS(index+1, ds, s, sum, arr, n);
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    printS(0, ds, 0, sum, arr, n);

    return 0;
}