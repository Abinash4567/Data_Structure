#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1;  

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

   int n, m;
   cin>>n>>m;

   vector<int> dp(m, 1);
   for(int i=0; i<n-1; i++)
   {
      vector<int> temp(m, 1);
      for(int j=1; j<m; j++)
         temp[j] = dp[j] + temp[j-1];
      dp = temp;
   }
   for(int i:dp)
      cout<<i<<"  ";

  #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
  #endif

   return 0;
}