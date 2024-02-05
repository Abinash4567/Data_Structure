#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1;  

int recurse(vector<int> arr, int n, int index)
{
   if(!index)
      return arr[index];
   if(index < 0)
         return 0;
   int noTake = 0 + recurse(arr, n, index-1);
   int take = arr[index] + recurse(arr, n, index - 2);
   return max(noTake, take);
}

int memo(vector<int> arr, int n, int index, vector<int> dp)
{
   if(!index)
      return arr[index];

   if(index < 0)
         return 0;
   if(dp[index]!=-1)
         return dp[index];

   int noTake = 0 + recurse(arr, n, index-1);
   int take = arr[index] + recurse(arr, n, index - 2);
   return dp[index] = max(noTake, take);
}

int opt(vector<int> arr, int n)
{
   vector<int> dp(n+1, 0);
   dp[0] = arr[0];
   dp[1] = arr[1];

   for(int index=2; index<n; index++)
   {
      int noTake = 0 + dp[index-1];
      int take = arr[index] + dp[index - 2];
      dp[index] = max(noTake, take);
   }
   return dp[n-1];
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   #ifndef ONLINE_JUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
   #endif

   vector<int> arr {1, 2, 3, 1};
   int n = arr.size();
   cout<<recurse(arr, n, n-1)<<endl;
   vector<int> dp(n+1, -1);
   cout<<memo(arr, n, n-1, dp)<<endl;
   cout<<opt(arr, n);

   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif

   return 0;
}