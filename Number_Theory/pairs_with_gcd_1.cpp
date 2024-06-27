#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1;  
const int mod = 1e9 + 7;
const int N = 1e6+10;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   #ifndef ONLINE_JUDGE
       clock_t tStart = clock();
   #endif

    vector<int> count(N, 0), cnt(N, 0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        count[temp]++;
    }

    for(int i=1; i<1000000; i++)
    {
        for(int j=i; j<1000000; j+=i)
            cnt[i] += count[j];
        cnt[i] = cnt[i] * (cnt[i]-1) / 2;
    }

    for(int i=1000000; i>=1; i--)
        for(int j=2*i; j<=1000000; j+=i)
            cnt[i] -= cnt[j];
        
    cout<<cnt[1];



   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif
   return 0;
}