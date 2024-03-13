#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1; 

int solve(vector<int> arr, int prevIndex, int currIndex, int n)
{
   if(currIndex == n)
      return 0;
   if(prevIndex==-1 or arr[prevIndex] < arr[currIndex])
      return max(1+solve(arr, currIndex, currIndex+1, n), solve(arr, prevIndex, currIndex+1, n));
   else
      return solve(arr, prevIndex, currIndex+1, n);
}

int tabulate(vector<int> arr, int n)
{
   vector<int> dp(n+1, 0);
   for(int currIndex=n-1; currIndex>=0; currIndex--)
   {
      vector<int> curr(n+1, 0);
      for(int prevIndex=currIndex-1; prevIndex>=-1; prevIndex--)
      {
      if(prevIndex==-1 or arr[prevIndex] < arr[currIndex])
         curr[prevIndex+1] = max(1 + dp[currIndex+1], dp[prevIndex+1]);
      else
         curr[prevIndex+1] = dp[prevIndex+1];
      }
      dp = curr;
   }
   return dp[0];
}

int hashing(vector<int> arr, int n)
{
   vector<int> hash(n, 0), dp(n, 1);
   int maxi = INT_MIN, lastIndex = -1;
   for(int i=1; i<n; i++)
   {
      for(int prev = 0; prev<i; prev++)
      {
         if(arr[i] > arr[prev] and 1 + dp[prev] > dp[i])
         {
            dp[i] = 1 + dp[prev]; 
            hash[i] = prev;
         }
      }
      if(dp[i]>maxi)
      {
         maxi = dp[i];
         lastIndex = i;
      }
   }

   vector<int> temp;
   temp.push_back(arr[lastIndex]);

   while(hash[lastIndex]!=lastIndex)
   {
      lastIndex = hash[lastIndex];
      temp.push_back(arr[lastIndex]);
   }
   reverse(temp.begin(), temp.end());
   for(int i:temp)
      cout<<i<<"  ";
   cout<<endl;
   return maxi;
}

int binSearch(vector<int> arr, int n)
{
   vector<int> temp;
   temp.push_back(arr[0]);
   for(int i=1; i<n; i++)
   {
      if(temp.back() < arr[i])
      {
         temp.push_back(arr[i]);
      }
      else
      {
         int index = lower_bound(arr.begin(), arr.end(), arr[i])-arr.begin();
         temp[index] = arr[i];
      }
   }
   return temp.size();
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
   cout<<solve(arr, -1, 0, n)<<endl;
   cout<<tabulate(arr, n)<<endl;
   cout<<hashing(arr, n)<<endl;
   cout<<binSearch(arr, n);









   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif

   return 0;
}