#include <iostream>
	using namespace std;

int swap_bits(int n)
{
	return ((n & 0xaaaaaaaa)>>1) | ((n & 0x55555555)<<1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;

	cout<<"After swappping odds and even bits place: "<<swap_bits(n);

	return 0;
}