#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1; 

int recurse(int index, int k, int buy, vector<int> arr)
{
   if(index==arr.size() or k==0)
      return 0;

   int profit = 0;
   if(buy)
   {
      profit = max(-arr[index]+recurse(index+1, k, 0, arr), recurse(index+1, k, buy, arr));
   }
   else
   {
      profit = max(arr[index]+recurse(index+1, k-1, 1, arr), recurse(index+1, k, buy, arr));
   }
   return profit;
}

int memo(int index, int k, int buy, vector<int> arr, vector<vector<vector<int>>> &dp)
{
   if(index==arr.size() or k==0)
   return 0;

   if(dp[index][k][buy]!=-1)
      return dp[index][k][buy];

   int profit = 0;
   if(buy)
   {
      profit = max(-arr[index]+memo(index+1, k, 0, arr, dp), memo(index+1, k, buy, arr, dp));
   }
   else
   {
      profit = max(arr[index]+memo(index+1, k-1, 1, arr, dp), memo(index+1, k, buy, arr, dp));
   }
   return dp[index][k][buy] = profit;
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

   int n, k;
   cin>>n;
   cin>>k;
   vector<int> arr(n, 0);
   for(int i=0; i<n; i++)
   {
      int temp;
      cin>>temp;
      arr[i] = temp;
   }
   cout<<recurse(0, k, 1, arr)<<endl;
   vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
   cout<<memo(0, k, 1, arr, dp)<<endl;

   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif

   return 0;
}