#include <bits/stdc++.h>
        using namespace std;


/* ===================== Euler’s Totient Function ======================= */
//         Natural Number from 1 to N-1 such that gcd(a, N)=1  
int phi(int n)
{
	int result = n;

	for(int p = 2; p * p <= n; ++p)
	{
		if (n % p == 0)
		{
			while (n % p == 0)
				n /= p;	
			result -= result / p;
		}
	}

	if (n > 1)                            //Next prime factor after root N
		result -= result / n;	
	return result;
}

int main()
{
	int n;
	cin>>n;
		cout << "Phi" << "("<< n << ")" << " = "<< phi(n);
	return 0;
}