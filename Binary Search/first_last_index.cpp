#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
const ll INF = LLONG_MAX >> 1; 

int indexFirst(vector<int> arr, int target)
{
    int low = 0, high = arr.size() - 1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(arr[mid] > target)
        {
            high = mid - 1;
        }
        else if(arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            if(mid==0 or arr[mid]!=arr[mid-1])
                return mid;
            else
                high = mid - 1; 
        }
    }
    return -1;
} 

int indexLast(vector<int> arr, int target)
{
    int low = 0, high = arr.size() - 1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(arr[mid] > target)
        {
            high = mid - 1;
        }
        else if(arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            if(mid==arr.size()-1 or arr[mid]!=arr[mid+1])
                return mid;
            else
                low = mid + 1;
        }
    } 
    return -1;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   #ifndef ONLINE_JUDGE
       clock_t tStart = clock();
   #endif



    vector<int> arr{1, 2, 3, 45, 45, 45, 67, 67, 89};
    int firstIndex = indexFirst(arr, 45);
    int lastIndex = indexLast(arr, 45);
    cout<<firstIndex<<endl;
    cout<<lastIndex;



   #ifndef ONLINE_JUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
   #endif
   return 0;
}