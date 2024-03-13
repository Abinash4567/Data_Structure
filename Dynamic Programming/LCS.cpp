#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1; 

int recurse(string str1, string str2, int index1, int index2)
{
   if(index1<0 or index2 < 0)
      return 0;
   if(str1[index1]==str2[index2])
      return 1+recurse(str1, str2, index1-1, index2-1);
   else
      return max(recurse(str1, str2, index1-1, index2), recurse(str1, str2, index1, index2-1));
}

int memo(string str1, string str2, int index1, int index2, vector<vector<int>> &dp)
{
   if(index1<0 or index2 < 0)
      return 0;

   if(dp[index1][index2]!=-1)
         return dp[index1][index2];

   if(str1[index1]==str2[index2])
      return dp[index1][index2] = 1+recurse(str1, str2, index1-1, index2-1);
   else
      return dp[index1][index2] = max(recurse(str1, str2, index1-1, index2), recurse(str1, str2, index1, index2-1));
}

int tabulate(string str1, string str2)
{
   int n = str1.size(), m = str2.size();
   vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

   for(int i=0; i<=n; i++)
      dp[i][0] = 0;

   for(int i=0; i<=m; i++)
      dp[0][i]=0;

   for(int i=1; i<=n; i++)
   {
      for(int j=1; j<=m; j++)
      {
         if(str1[i-1]==str2[j-1])
            dp[i][j] = 1+dp[i-1][j-1];
         else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
   }
   return dp[n][m];
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

   string str1, str2;
   cin>>str1>>str2;
   int n = str1.size(), m = str2.size();
   cout<<recurse(str1, str2, n-1, m-1)<<endl;
   vector<vector<int>> dp(n, vector<int>(m, -1));
   cout<<memo(str1, str2, n-1, m-1, dp)<<endl;
   cout<<tabulate(str1, str2);


   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif

   return 0;
}