#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1; 

int recurse(int n)
{
   if(n<=1)
      return n;
   return recurse(n-1) + recurse(n-2);
}

int memo(int n, vector<int> &dp)
{
   if(n<=1)
      return n;
   if(dp[n]!=-1)
      return dp[n];
   return dp[n]=memo(n-1, dp) + memo(n-2, dp);
}

int tabulate(int n)
{
   vector<int> dp(n+1, 0);
   dp[1] = 1;
   for(int i=2; i<=n; i++)
      dp[i] = dp[i-1] + dp[i-2];
   return dp[n];
}

int spaceOpt(int n)
{
   if(n<=1)
      return n;
   
   int prev = 0, curr = 1;
   for(int i=2; i<=n; i++)
   {
      int next = prev + curr;
      prev = curr;
      curr = next;
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



   //start code here
   int n;
   cin>>n;
   cout<<recurse(n)<<endl;
   vector<int> dp(n+1, -1);
   cout<<memo(n, dp)<<endl;
   cout<<tabulate(n)<<endl;
   cout<<spaceOpt(n);


   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif

   return 0;
}