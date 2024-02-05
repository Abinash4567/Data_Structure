#include <iostream>
#include <vector>
	using namespace std;

//============ Rotated_Array =================== 

int Pivot_Index(vector<int> arr)
{
	int lo=0, hi=arr.size()-1;

	while(lo<hi)
	{
		int mid=lo+(hi-lo)/2;

		if(arr[mid]>=arr[0])
		{
			lo=mid+1;
		}
		else
		{
			hi=mid;
		}
	}
	return arr[hi];
}
int main()
{
	vector<int> arr {4, 5, 6, 7, 8, 1, 2, 3};
	cout<<Pivot_Index(arr);
	return 0;
}