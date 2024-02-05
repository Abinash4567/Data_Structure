#include <iostream>
#include <vector>
	using namespace std;

int bin_search_rotated(vector<int> arr, int key)
{
	int n=arr.size();
	int lo=0, hi=n-1;

	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;
		if(arr[mid]==key)
			return mid;

		if(arr[lo]<=arr[mid])        //left sorted
		{
			if(key>=arr[lo] and key<arr[mid])
				hi=mid-1;
			else
				lo=mid+1;	
		}
		else if(arr[mid]<=arr[hi])
		{
			if(key<=arr[hi] and key>arr[mid])
				lo=mid+1;
			else
				hi=mid-1;
		}
	}
	return -1;
}

int main()
{
	vector<int> arr {5, 6, 7, 8, 9, 10, 1, 2, 3};
	int key;
	cin>>key;

	cout<<key<<" found at "<<bin_search_rotated(arr, key);

	return 0;
}