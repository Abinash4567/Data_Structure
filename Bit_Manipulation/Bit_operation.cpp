#include <iostream>
     using namespace std;

// ========================= Bit Manipulation =======================
int main()
{
	int a, b;
	cin>>a>>b;

	// Turn of last bit of a 
	int c = a & (a-1);

	// Make last bit intact
	int d = a & ~(a-1);

	return 0;
}