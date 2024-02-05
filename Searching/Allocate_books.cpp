#include <iostream>
#include <vector>
	using namespace std;

bool is_Possible(vector<int> arr, int sts, int mid)
{
	int spc=0, ns=1;
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i]>mid)
			return false;

		if(spc+arr[i]<=mid)
		{
			spc+=arr[i];
		}
		else
		{
			ns++;
			if(ns>sts)
				return false;
			spc=arr[i];
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    vector<int> arr {12, 34, 67, 90};
    int sts=2;

    int lo=arr[0], hi=0;

    for(int i=0;i<arr.size();i++)
    {
    	lo=min(lo, arr[i]);
    	hi+=arr[i];
    }
    int res=-1;

    while(lo<=hi)
    {
    	int mid=lo+(hi-lo)/2;

    	if(is_Possible(arr, sts, mid))
    	{
    		res=mid;
    		hi=mid-1;
    	}
    	else
    	{
    		lo=mid+1;
    	}
    }
    if (sts > arr.size())
        res=-1;

    cout<<"Minimum books allocated is "<<res;

	return 0;
}