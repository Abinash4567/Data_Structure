#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

    using namespace std;
    using namespace __gnu_pbds;

// find_by_order, order_of_key
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
//           data type       sorting  less_equal for multi set

// *find_by_order 
// order_of_key                                           

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pbds A; // declaration

    A.insert(12);
    A.insert(34);
    A.insert(98);
    A.insert(11);

    A.erase(11);

    cout<<"A: ";
    for(int i:A)
        cout<<i<<" ";

    cout<<endl;

    cout<<*A.find_by_order(1)<<endl;

    cout<<A.order_of_key(98);

    return 0;
}