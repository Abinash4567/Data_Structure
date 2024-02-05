#include <bits/stdc++.h>
    using namespace std;

int tiling(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;

    return tiling(n-2)+tiling(n-1);
}


int main()
{
    int n=4;
    cout<<"Number of ways in which 2xn floor can be tiled with 2x1 tile"<<"\n";
    cout<<tiling(n);
    return 0;
}