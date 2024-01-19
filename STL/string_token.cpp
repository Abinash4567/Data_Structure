#include <bits/stdc++.h>
    using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char str[100] = "   Today is a rainy day    giugi";
    char *ptr = strtok(str, " ");

    while(ptr)
    {
        ptr = strtok(NULL, " ");
        cout<<ptr<<endl;
    }

    return 0;
}
