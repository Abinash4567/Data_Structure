#include <iostream>
#include <vector>
    using namespace std;

void Print_unique(vector<int> arr)
{
	int xo = 0;

	for(int i=0;i<arr.size();i++)
		xo^=arr[i];

	int check = xo & ~(xo-1);

	int num1=0, num2=0;

	for(int i=0;i<arr.size();i++)
	{
		if(check & arr[i])
			num1^=arr[i];
		else
			num2^=arr[i];
	}

	cout<<num1<<"  "<<num2;
}

int main()
{
	int n;
	cin>>n;

	vector<int> arr(n, 0);

	for(int i=0;i<n;i++)
		cin>>arr[i];

	Print_unique(arr);
	return 0;
}