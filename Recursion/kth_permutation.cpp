#include <bits/stdc++.h>
    using namespace std;

string kTh_permutation(int n, int k)
{
    vector<int> num;
    int fact=1;

    for(int i=1;i<n;i++)
    {
        fact*=i;
        num.push_back(i);
    }

    num.push_back(n);
    string str="";
    k--;

    while(1)
    {
        str+=to_string(num[k/fact]);
        num.erase(num.begin()+(k/fact));

        if(num.size()==0)
            break;

        k%=fact;
        fact/=num.size();
    }

    return str;
}

int main()
{
    cout<<kTh_permutation(4, 9);
    return 0;
}


