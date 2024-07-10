#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1;

class DisjointSet {
public:
    vector<int> parent, rank, size;
    DisjointSet(int n)
    {
        parent.resize(n+1, 0);
        rank.resize(n+1, 0);
        size.resize(n+1, 0);

        for(int i=0; i<=n; i++)
            parent[i] = i;
    }

    int findParent(int m)
    {
        if(m==parent[m])
            return m;
        else 
            return parent[m] = findParent(parent[m]);
    }

    void unionByRank(int u, int v)
    {
        if(parent[u]==parent[v])
            return;
        if(rank[parent[u]]==rank[parent[v]])
        {
            parent[parent[u]] = parent[v];
            rank[u]++;
        }
        else if(rank[parent[u]] > rank[parent[v]])
        {
            parent[parent[u]] = parent[parent[v]];
        }
        else
        {
            parent[parent[v]] = parent[parent[u]];
        }    
    }

    void unionBySize(int u, int v)
    {
        if(parent[u]==parent[v])
            return;
        if(size[parent[u]] < size[parent[v]])
        {
            size[parent[v]] += size[parent[u]];
            parent[parent[v]] = parent[v];
        }
        else
        {
            size[parent[u]] += size[parent[v]];
            parent[parent[u]] = parent[v];
        }
    }
};

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   #ifndef ONLINE_JUDGE
       clock_t tStart = clock();
   #endif

    DisjointSet s1(7);
    s1.unionBySize(1, 2);
    s1.unionBySize(2, 3);
    s1.unionBySize(4, 5);
    s1.unionBySize(6, 7);
    s1.unionBySize(5, 6);
    s1.unionBySize(3, 7);

    if(s1.findParent(3)==s1.findParent(7))
        cout<<"True";



   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif
   return 0;
}