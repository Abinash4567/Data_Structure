#include <iostream>
	using namespace std;

int cons(int n)
{
	int count = 0;

	while(n)
	{
		n = (n & (n<<1));
		count++;
	}
	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;

	cout<<"Number of consecutive 1s is: "<<cons(n);

	return 0;
}