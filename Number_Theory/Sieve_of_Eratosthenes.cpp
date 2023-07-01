#include <iostream>
#include <vector>
    using namespace std;


void Sieve_of_Eratosthenes(int n, vector<int> &arr)
{
	for(int i=2;i*i<=n;i++)
	{
		if(arr[i]==1)
		{
			for(int j=i*i;j<=n;j+=i)
				arr[j]=0;
		}
	}
}


int main()
{
	int n;
	cin>>n;
	vector<int> is_Prime(n+1, 1);
	is_Prime[0]=is_Prime[1]=0;
	Sieve_of_Eratosthenes(n, is_Prime);

	for(int k=1;k<=n;k++)
		cout<<is_Prime[k]<<endl;

	return 0;
}



/*    Time Complexity: O(n*log(logn))
      Aixiliary Space: O(n)             */