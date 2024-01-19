#include <bits/stdc++.h>
    using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, T;
    getline(cin, str);

    stringstream X(str);

    while(getline(X, T, ' '))
        cout<<T<<endl;

    return 0;
}