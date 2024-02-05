#include <iostream>
#include <math.h>
    using namespace std;

void Print_Prime_Factor(int n)
{
	if(n<=1)
		return;

	while(n%2==0)
	{
		n/=2;
		cout<<2<<"  ";
	}

	while(n%3==0)
	{
		n/=3;
		cout<<3<<"  ";
	}


	for (int i = 5; i <= n; i+=6)
	{
		while(n%i==0)
		{
			n/=i;
			cout<<i<<"  ";
		}

		while(n%(i+2)==0)
		{
			n/=(i+2);
			cout<<(i+2)<<"  ";
		}
	}
}

int main()
{
	int n;
	cin>>n;
	Print_Prime_Factor(n);
	return 0;
}