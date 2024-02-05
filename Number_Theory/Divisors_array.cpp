#include <iostream>
#include <vector>
    using namespace std;

void Divisors_array(vector<vector<int>> &arr, int n)
{
	for(int i=2;i<=n;i++)
	{
		for(int j=i;j<=n;j+=i)      //Goes through multiple of i
			arr[j].push_back(i);    //Put number into divisors
	}
}

 int main()
 {
 	int n;
 	cin>>n;
 	vector<vector<int>> arr(n+1);
 	arr[1].push_back(1);
 	Divisors_array(arr, n);

 	for(int i=1;i<=n;i++)
 	{
 		for(auto div:arr[i])
 			cout<<div<<"  ";
 		cout<<endl;
 	}

 	return 0;
 }