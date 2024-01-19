#include <bits/stdc++.h>
    using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1;  


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a {1, 2, 3, 2};
    int b = 2;

    int xo = 0;
    unordered_map<int, int> map;
    map[xo] = 1;
    int count = 0;

    for(int i=0; i<a.size(); i++)
    {
        xo ^= a[i];

        int finding = xo ^ b;
        if(map.find(finding)!=map.end())
            count+=map[finding];
        map[xo]++;
    }
    cout<<"Number of subarray with xor sum "<<b<<": "<<count;

    return 0;
}