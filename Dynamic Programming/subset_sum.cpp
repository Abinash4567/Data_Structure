#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1;

bool recurse(vector<int> arr, int k, int n, int index)
{
   if(k==0)
      return true;
   if(index == 0)
      return k==arr[index];

   bool noTake = recurse(arr, k, n, index - 1);
   bool take = false;
   if(arr[index]<=k)
         take = recurse(arr, k-arr[index], n, index-1);
   return noTake or take;
}

bool memo(vector<int> arr, int k, int n, int index, vector<vector<int>> &dp)
{
   if(k==0)
      return 1;

   if(index == 0)
      return k==arr[index];

   if(dp[index][k]!=-1)
      return dp[index][k];

   bool noTake = recurse(arr, k, n, index - 1);
   bool take = false;
   if(arr[index]<=k)
         take = recurse(arr, k-arr[index], n, index-1);
   return dp[index][k] = (noTake or take);
}

bool tabulate(vector<int> arr, int k, int n)
{
   vector<vector<bool>> dp(n, vector<bool>(k+1, false));
   for(int i=0; i<n; i++)
      dp[i][0] = true;

   if(arr[0]<=k)
      dp[0][arr[0]] = true;

   for(int i=1; i<n; i++)
   {
      for(int j=1; j<=k; j++)
      {
         bool noTake = dp[i-1][j];
         bool take = false;
         if(arr[i] <= j)
            take = dp[i-1][j-arr[i]];
         dp[i][j] = take or noTake;
      }
   }
   return dp[n-1][k];
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

   int n;
   cin>>n;
   vector<int> arr(n, 0);
   for(int i=0; i<n; i++)
   {
      int temp;
      cin>>temp;
      arr[i]=temp;
   }
   int k;
   cin>>k;
   cout<<recurse(arr, k , n, n-1)<<endl;
   vector<vector<int>> dp(n, vector<int>(k+1, -1));
   cout<<memo(arr, k, n, n-1, dp)<<endl;
   cout<<tabulate(arr, k, n);

   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif

   return 0;
}