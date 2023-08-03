#include <bits/stdc++.h>
    using namespace std;

int printS(int index, int s, int sum, int arr[], int n)
{
    if(index==n)
    {
        if(sum==s)
            return 1;
        return 0;

    }

    int a =printS(index+1, s, sum, arr, n);
    
    s+=arr[index];

    int b=printS(index+1, s, sum, arr, n);

    return a+b;

}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    cout<<printS(0, 0, sum, arr, n);




    return 0;
}