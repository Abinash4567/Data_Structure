#include <iostream>
#include <math.h>
    using namespace std;

void Trailing_zeros_in_factorial(int n)
{
	int res=0;
	for(int i=5;i<=n;i*=5)
		res+=floor(n/i);
	cout<<res;
}

int main()
{
	int n;
	cin>>n;
	Trailing_zeros_in_factorial(n);
	return 0;
}