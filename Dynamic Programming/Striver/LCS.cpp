#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1; 

int longestCommonSubsequence(string str1, string str2, int index1, int index2)
{
   if(index1<0 or index2<0)
      return 0;
   if(str1[index1]==str2[index2])
      return 1+longestCommonSubsequence(str1, str2, index1-1, index2-1);
   else
      return max(longestCommonSubsequence(str1, str2, index1-1, index2), longestCommonSubsequence(str1, str2, index1, index2-1));
}

int memo(string str1, string str2, int index1, int index2, vector<vector<int>> &dp)
{
   if(index1==0 or index2==0)
      return 0;
   if(dp[index1][index2]!=-1)
      return dp[index1][index2];
   if(str1[index1-1]==str2[index2-1])
      return dp[index1][index2]=1+memo(str1, str2, index1-1, index2-1, dp);
   else
      return dp[index1][index2]=max(memo(str1, str2, index1-1, index2, dp), memo(str1, str2, index1, index2-1, dp));
}

int tabulate(string str1, string str2, int n1, int n2)
{
   vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));

   for(int index1=0; index1<=n1; index1++)
   {
      for(int index2=0; index2<=n2; index2++)
      {
         if(index1==0 or index2==0)
            dp[index1][index2] = 0;
         else if(str1[index1-1]==str2[index2-1])
            dp[index1][index2] = 1 + dp[index1-1][index2-1];
         else
            dp[index1][index2]=max(dp[index1-1][index2], dp[index1][index2-1]);
      }
   }
   string temp;
   int i=n1, j=n2;
   while(i>0 and j>0)
   {
      if(str1[i-1]==str2[j-1])
      {
         temp.push_back(str1[i-1]);
         i--;
         j--;
      }
      else
      {
         if(dp[i-1][j] > dp[i][j-1])
         {
            temp.push_back(str1[i-1]);
            i--;
         }
         else
         {
            temp.push_back(str2[j-1]);
            j--;
         }
      }
   }
   while(i>0)
   {
      temp.push_back(str1[i-1]);
         i--;
   }
   while(j>0)
   {
      temp.push_back(str2[j-1]);
         j--;
   }
   reverse(temp.begin(), temp.end());
   cout<<temp<<endl;

   return dp[n1][n2];
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
   string str1 = "brute";
   string str2 = "groot";
   int n1 = str1.size(), n2 = str2.size();
   cout<<longestCommonSubsequence(str1, str2, n1-1, n2-1)<<endl;
   vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
   cout<<memo(str1, str2, n1, n2, dp)<<endl;
   cout<<tabulate(str1, str2, n1, n2)<<endl;



   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif

   return 0;
}