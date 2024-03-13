#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1; 

int recurse(vector<int> arr, int index)
{
   if(index==0)
      return arr[index];
   else if(index<0)
         return 0;

   int take = arr[index] + recurse(arr, index - 2);
   int notake = recurse(arr, index - 1);
   return max(take, notake);
}

int memo(vector<int> arr, int index, vector<int> &dp)
{
   if(index == 0)
      return arr[index];
   else if(index < 0)
         return 0;

   if(dp[index]!=-1)
         return dp[index];

   int take = arr[index] + memo(arr, index - 2, dp);
   int notake = memo(arr, index - 1, dp);
   return dp[index] = max(take, notake);
}

int tabulate(vector<int> arr, int n)
{
   vector<int> dp(n+1, 0);
   dp[0] = arr[0];
   for(int index=1; index<=n; index++)
   {
      int take = arr[index];
      if(index-2 >= 0)
         take += dp[index - 2];
      int notake = dp[index - 1];
      dp[index] = max(take, notake);
   }
   return dp[n];
}

int spaceOpt(vector<int> arr, int n)
{
   int prev = 0, curr = arr[0];
   for(int index=1; index<n; index++)
   {
      int take = arr[index];
      if(index-2 >= 0)
         take += prev;
      int notake = curr;
      int next = max(take, notake);

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
   vector<int> arr;
   for(int i=0; i<n; i++)
   {
      int temp;
      cin>>temp;
      arr.push_back(temp);
   }
   cout<<recurse(arr, n-1)<<endl;
   vector<int> dp(n+1, -1);
   cout<<memo(arr, n-1, dp)<<endl;
   cout<<tabulate(arr, n)<<endl;
   cout<<spaceOpt(arr, n);


   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif

   return 0;
}