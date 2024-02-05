#include <bits/stdc++.h>
    using namespace std;

vector<int> intersection(vector<int> arr1, vector<int> arr2)
{
    vector<int> ans;

    int i=0, j=0;

    while(i<arr1.size() and j<arr2.size())
    {
        if(arr1[i]<arr2[j])
        {
            i++;
        }
        else if(arr1[i]>arr2[j])
        {
            j++;
        }
        else
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return ans;
}


int main()
{
    vector<int> arr1 = {1, 1, 2, 3, 4, 5};
    vector<int> arr2 = {1,2, 8, 9, 10, 11};

    vector<int> ans = intersection(arr1, arr2);

    for(int i:ans)
        cout<<i<<"  ";

    return 0;
}