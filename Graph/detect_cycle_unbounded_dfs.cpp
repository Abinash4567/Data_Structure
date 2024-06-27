#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1;  

bool dfs(int node, int prev, vector<int> adj[], int vis[])
    {
        vis[node] = 1;
        for(int i:adj[node])
        {
            if(!vis[i])
            {
                if(dfs(i, node, adj, vis))
                    return true;
            }
            else if(i!=prev)
            {
                return true;
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
  int vis[V] = {0};
  for(int i=0; i<V; i++)
  {
      if(!vis[i])
      {
          if(dfs(i, -1, adj, vis))
              cout<<"true";
      }
  }
  cout<<"false";
   


   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif

   return 0;
}