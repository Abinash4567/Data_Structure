#include <iostream>
#include <vector>
	using namespace std;

//============Mountain=================== 

int Peak_Index(vector<int> arr)
{
	int lo=0, hi=arr.size()-1;
	while(lo<hi)
	{
		int mid=lo+(hi-lo)/2;
		if(arr[mid]<arr[mid+1])
			lo=mid+1;
		else
			hi=mid;
	}
	return arr[lo];
}
int main()
{
	vector<int> arr {1, 2, 3, 4, 9, 8, 7, 6, 5};
	cout<<Peak_Index(arr);
	return 0;
}