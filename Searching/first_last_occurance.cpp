#include <iostream>
#include <vector>
	using namespace std;

int first_occurance(vector<int> arr, int n, int a)
{
	int lo=0, hi=n-1, res=-1;

	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;
		if(arr[mid]>a)
		{
			hi=mid-1;
		}
		else if(arr[mid]<a)
		{
			lo=mid+1;
		}
		else if(arr[mid]==a)
			{
				res=mid;
				hi=mid-1;
			}
	}
	return res;
}

int last_occurance(vector<int> arr, int n, int a)
{
	int lo=0, hi=n-1, res=-1;

	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;
		if(arr[mid]>a)
		{
			hi=mid-1;
		}
		else if(arr[mid]<a)
		{
			lo=mid+1;
		}
		else if(arr[mid]==a)
			{
				res=mid;
				lo=mid+1;
			}
	}
	return res;
}

int main()
{
	int a;
	cin>>a;
	vector<int> arr{1, 3, 5, 5, 5, 5, 67, 123, 125};
	int n=arr.size();
	cout<<"First Occurance of "<<a<<" is "<<first_occurance(arr, n, a)<<endl;
	cout<<"Last Occurance of "<<a<<" is "<<last_occurance(arr, n, a)<<endl;	

	return 0;
}