#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1;  

int recurse(int n, int k, vector<int> arr, int index)
{
   if(index == 0)
      return 0;

   int mini = INT_MAX;

   for(int i=1; i<=k; i++)
      if((index - i) >= 0)
         mini = min(abs(arr[index] - arr[index-i])+recurse(n, k, arr, index - i), mini);

   return mini; 
}

int memo(int n ,int k, vector<int> arr, int index, vector<int> dp)
{
   if(index == 0)
      return 0;

   if(dp[index]!=-1)
      return dp[index];

   int mini = INT_MAX;
   for(int i=1; i<=k; i++)
   {
      if(index - i >=0)
         mini = min(abs(arr[index]-arr[index-i])+memo(n, k, arr, index-i, dp), mini);
   }
   return dp[index] = mini;
}

int opt(int n, int k, vector<int> arr)
{
   vector<int> dp(n+1, 0);
   for(int i=1; i<n; i++)
   {
      int mini = INT_MAX;
      for(int j=1; j<=k; j++)
      {
         if((i-j)>=0)
            mini = min(abs(arr[i]-arr[i-j])+dp[i-j], mini);
      }
      dp[i] = mini;
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

   int n=5, k=3;
   vector<int> arr = {10, 40, 50, 20, 60};  
   cout<<recurse(n, k, arr, n-1)<<endl;
   vector<int> dp(n+1, -1);
   cout<<memo(n, k, arr, n-1, dp)<<endl;
   cout<<opt(n, k, arr);


   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif

   return 0;
}