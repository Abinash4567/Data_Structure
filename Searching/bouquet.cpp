#include <iostream>
#include <vector>
	using namespace std;

bool is_pos(vector<int> arr, int boq, int flowers, int mid)
{
	int se=0, fcount=0; 
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i]<=mid)
		{
			se++;
		
			if(se==boq)
			{
				fcount++;
				se=0;
			}
			if(fcount==flowers)
				return true;
		}
		else
		{
			se=0;
		}
	}
	return false;
}

int min_day(vector<int> arr, int boq, int flowers)
{
	if((boq*flowers)>arr.size())
		return -1;

	int lo=arr[0], hi=arr[0];

	for(int i:arr)
	{
		hi=max(hi, i);
		lo=min(lo, i);
	}
	int res=-1;

	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;
		if(is_pos(arr, boq, flowers, mid))
		{
			res=mid;
			hi=mid-1;
		}
		else
		{
			lo=mid+1;
		}

	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    vector<int> arr {2, 5, 2, 9, 3, 10, 4, 6, 5, 6};
    int boq=4;
    int flowers=2;

    cout<<min_day(arr, boq, flowers);
	return 0;
}