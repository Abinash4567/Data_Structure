#include <iostream>
#include <math.h>
	using namespace std;


int main()
{
	int n;
	cin>>n;

	int div = 5;
	int count = 0;

	while(n/div)
	{
		count += floor(n/div);
		div*=5;
	}

	cout<<"Number of trailing zeros in factorial of "<<n<<" is "<<count;
	return 0;
}
