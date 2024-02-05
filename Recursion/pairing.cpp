#include <bits/stdc++.h>
    using namespace std;

int pairing(int n)
{
    if(n==0 or n==1 or n==2)
        return 1;
    return pairing(n-1)+pairing(n-2)*(n-1);
}


int main()
{
    cout<<"Number of ways in which N friends can be single or paired:";
    cout<<pairing(8);
    return 0;
}