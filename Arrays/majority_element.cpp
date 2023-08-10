#include <bits/stdc++.h>
    using namespace std;

int majority(vector<int> arr)
{
    int count=1;
    int res=0;

    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]==arr[res])
        {
            count++;
        }
        else if(arr[i]!=arr[res])
        {
            count--;
            if(count == 0)
            {
                count=1;
                res=i;
            }
        }
    }
    return arr[res];
}


int main()
{
    vector<int> arr = {0, 1, 2, 1 , 2, 1, 2 ,1, 1};

    cout<<"Majority Element is:"<<majority(arr);

    return 0;
}