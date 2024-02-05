#include <iostream>
#include <math.h>
	using namespace std;


int main()
{
	int a, b;
	cin>>a>>b;

	if(b>a)
		swap(a, b);

	int rem;

	while(b)
	{
		rem = a%b;
		a=b;
		b=rem;
	}

	cout<<a<<endl;
	cout<<__gcd(a, b);     //stk to get gcd 

	return 0;
}
