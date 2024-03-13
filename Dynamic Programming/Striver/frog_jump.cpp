#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1; 

int recurse(vector<int> arr, int n)
{
   if(n==0)
      return 0;
   int option1 = recurse(arr, n-1) + abs(arr[n] - arr[n-1]);
   int option2 = INT_MAX;
   if(n>=2)
      option2 = recurse(arr, n-2) + abs(arr[n] - arr[n-2]);
   return min(option1, option2);
}

int memo(vector<int> arr, vector<int> &dp, int n)
{
   if(n==0)
      return 0;
   if(dp[n]!=-1)
      return dp[n];
   int option1 = recurse(arr, n-1) + abs(arr[n] - arr[n-1]);
   int option2 = INT_MAX;
   if(n>=2)
      option2 = recurse(arr, n-2) + abs(arr[n] - arr[n-2]);
   return dp[n] = min(option1, option2);
}

int tabulate(vector<int> arr, int n)
{
   vector<int> dp(n+1, -1);
   dp[0] = 0;
   for(int i=1; i<=n; i++)
   {
      int option1 = dp[i-1] + abs(arr[i] - arr[i-1]);
      int option2 = INT_MAX;
      if(i>=2)
         option2 = dp[i-2] + abs(arr[i] - arr[i-2]);
      dp[i] = min(option1, option2);
   }
   return dp[n];
}

int spaceOpt(vector<int> arr, int n)
{
   int prev , curr = 0;
   for(int i=1; i<=n; i++)
   {
      int option1 =  curr + abs(arr[i] - arr[i-1]);
      int option2 = INT_MAX;
      if(i>=2)
         option2 = prev + abs(arr[i] - arr[i-2]);
      int next = min(option1, option2);
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
   cout<<memo(arr, dp, n-1)<<endl;
   cout<<tabulate(arr, n-1)<<endl;
   cout<<spaceOpt(arr, n-1);


   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif

   return 0;
}