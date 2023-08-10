#include <bits/stdc++.h>
    using namespace std;

int remove_dup(vector<int> &arr)
{
    int i=0;

    for(int j=1;j<arr.size();j++)
    {
        if(arr[i]==arr[j])
        {
            continue;
        }
        else
        {
            arr[++i]=arr[j];

        }

    }
    return ++i;
}



int main()
{
    vector<int> arr ={1, 2, 4, 7, 8, 10};

    remove_dup(arr);

    for(int i:arr)
        cout<<i<<"  ";
    return 0;
}