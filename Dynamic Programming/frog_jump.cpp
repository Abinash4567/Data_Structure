#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1;

int solve(int index, int n, vector<int> arr, int dp[])
{
    if(index == n-1)
        return 0;
    if(dp[index]!=-1)
        return dp[index];

    int left = solve(index + 1, n, arr, dp) + abs(arr[index] - arr[index + 1]);
    int right = INT_MAX;
    if(index + 2 < n)
        right = solve(index + 2, n, arr, dp) + abs(arr[index] - arr[index+2]);
    return dp[index] = min(right, left);
}

int solveByTabulation(vector<int> arr)
{
    int curr = 0, prev = -1;
    int n = arr.size();
    for(int index=n-2; index>=0; index--)
    {
        int left = curr + abs(arr[index] - arr[index + 1]);
        int right = INT_MAX;
        if(index + 2 < n)
            right = prev + abs(arr[index] - arr[index+2]);
        prev = curr;
        curr = min(left, right);
    }
    return curr;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   #ifndef ONLINE_JUDGE
       clock_t tStart = clock();
   #endif


    //code
    vector<int> arr = {10, 20, 30, 10};
    int n = arr.size();
    int dp[n];
    memset(dp, -1, sizeof(arr));

    cout<<solve(0, n, arr, dp)<<endl;
    cout<<solveByTabulation(arr);


   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif
   return 0;
}