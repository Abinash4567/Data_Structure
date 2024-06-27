#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1;  

bool solve(vector<int> adj[], int vis[], int start, int n)
 {
     queue<pair<int, int>> que;
     que.push({start, -1});
     vis[start] = 1;
     
     while(que.size())
     {
         int node = que.front().first;
         int parent = que.front().second;
         que.pop();
         
         for(auto i:adj[node])
         {
             if(!vis[i])
             {
                 que.push({i, node});
                 vis[i] = 1;
                 
             }
             else if(vis[i] and i!=parent)
             {
                 return true;
             }
         }
     }
     return false;
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
   int V, E;
   cin >> V >> E;
   vector<int> adj[V];
   for (int i = 0; i < E; i++) 
   {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   int n = V;
  int vis[n] = {0};
  for(int i=0; i<n; i++)
  {
      if(!vis[i])
      {
          if(solve(adj, vis, i, n))
              cout<<true;
      }
  }
  cout<<false;
   


   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif

   return 0;
}