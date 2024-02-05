#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1; 

int recurse(int i, int j, int k, vector<vector<int>> grid, int n, int m)
{
   if(j<0 or j>=m or k<0 or k>=m)
      return INT_MIN;

   if(i==n-1)
   {
      if(j==k)
         return grid[i][j];
      else
         return grid[i][j] + grid[i][k];
   }

   int maxi = INT_MIN;
   for(int l=-1; l<=1; l++)
   {
      for(int p=-1; p<=1; p++)
      {
         int value = 0;
         if(j==k)
            value = grid[i][j];
         else
            value = grid[i][j] + grid[i][k];
         maxi = max(maxi, value + recurse(i+1, j+l, k+p, grid, n, m));
      }
   }
   return maxi;
} 

int memo(int i, int j, int k, vector<vector<int>> grid, int n, int m, vector<vector<vector<int>>> &dp)
{
   if(j<0 or j>=m or k<0 or k>=m)
      return INT_MIN;

   if(i==n-1)
   {
      if(j==k)
         return grid[i][j];
      else
         return grid[i][j] + grid[i][k];
   }

   if(dp[i][j][k]!=-1)
         return dp[i][j][k];

   int maxi = INT_MIN;
   for(int l=-1; l<=1; l++)
   {
      for(int p=-1; p<=1; p++)
      {
         int value = 0;
         if(j==k)
            value = grid[i][j];
         else
            value = grid[i][j] + grid[i][k];
         if((j+l)>=0 and (j+l)<m and (k+p)>=0 and (k+p)<m)
            maxi = max(maxi, value + recurse(i+1, j+l, k+p, grid, n, m));
      }
   }
   return dp[i][j][k] = maxi;
}

int tabulate(vector<vector<int>> grid, int n, int m)
{
   vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
   for(int i=0; i<m; i++)
   {
      for(int j=0; j<m; j++)
      {
         if(i==j)
            dp[n-1][i][j] = grid[n-1][j];
         else
            dp[n-1][i][j] = grid[n-1][j] + grid[n-1][i];
      }
   }

   for(int i=n-2; i>=0; i--)
   {
      for(int j=0; j<m; j++)
      {
         for(int k=0; k<m; k++)
         {
            int maxi = INT_MIN;

            for(int dj=-1; dj<=1; dj++)
            {
               for(int dk=-1; dk<=1; dk++)
               {
                  int ans;

                  if (j == k)
                      ans = grid[i][j];
                  else
                      ans = grid[i][j] + grid[i][k];

                  if((j+dj)>=0 and (j+dj)<m and (k+dk)>=0 and (k+dk)<m)
                        ans += dp[i+1][j+dj][k+dk];
                  else 
                     ans += INT_MIN;
                  maxi = max(maxi, ans);
               }
            }
            dp[i][j][k] = maxi;
         }
      }
   }
   return dp[0][0][m-1];  
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

   vector<vector<int>> grid{{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5,}};
   int row = grid.size(), col = grid[0].size(); 
   cout<<recurse(0, 0, col-1, grid, row, col)<<endl;
   vector<vector<vector<int>>> dp(col, vector<vector<int>>(col, vector<int>(col, -1)));
   cout<<memo(0, 0, col-1, grid, row, col, dp)<<endl;
   cout<<tabulate(grid, row, col);

   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif

   return 0;
}