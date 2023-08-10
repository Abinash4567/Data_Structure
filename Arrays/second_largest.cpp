#include <bits/stdc++.h>
    using namespace std;

int second_largest(int arr[], int n)
{
    int largest = arr[0];
    int second_largest = -1;

    for(int i=1;i<n;i++)
    {
        if(arr[i]>largest)
        {
            second_largest = largest;
            largest=arr[i];
        }
        else if(arr[i]<largest and second_largest<arr[i])
        {
            second_largest=arr[i];
        }
    }
    return second_largest;
}


int main()
{
    int arr[]={1, 2, 4, 7, 4, 3};
    cout<<second_largest(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}