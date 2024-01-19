#include <bits/stdc++.h>
    using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1;  


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr {2, 2, 1, 3, 1, 1, 3, 1, 1};
    int ele1 = INT_MIN, ele2 = INT_MIN;
    int count1 = 0, count2 = 0;

    for(int i=0; i<arr.size(); i++)
    {
        if(count1 == 0 and arr[i]!=ele2)
        {
            count1 = 1;
            ele1 = i;
        }
        else if(count2 ==0 and arr[i]!=ele1)
        {
            count2 = 1;
            ele2 = i;
        }
        else if(arr[i]==ele1)
        {
            count1++;
        }
        else if(arr[i]==ele2)
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    } 

    count1 = 0;
    count2 = 0;

    for(int i:arr)
    {
        if(i==ele1)
            count1++;
        else if(i==ele2)
            count2++;
    } 

    if(count1 >= 3)
        cout<<ele1;

    if(count2 >= 3)
        cout<<ele2;

    return 0;
}