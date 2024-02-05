#include <bits/stdc++.h>
    using namespace std;

void rotate_right(vector<int> &arr, int k)
{
    int n=arr.size();

    k=k%n;

    reverse(arr.begin(),arr.end());

    reverse(arr.begin(), arr.begin()+k);
    reverse(arr.begin()+k, arr.end());
}



int main()
{
    vector<int> arr ={1, 2, 4, 7, 8, 10};

    rotate_right(arr, 3);

    for(int i:arr)
        cout<<i<<"  ";

    return 0;
}