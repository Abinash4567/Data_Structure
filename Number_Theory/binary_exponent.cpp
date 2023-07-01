#include <iostream>
   using namespace std;

const int M = 1e9+7;
const long long MM=1e18+7;

//                Calculate bin_expo(A, m-2)= Inverse of A= A^(m-2)%m
/* ==========================  Recursive  Approach ====================== */
int bin_expo_recurr(int a, int b)
{
	if(b==0)
		return 1;
	int res=bin_expo_recurr(a, b/2);
	if(b&1)
		return (a*((res*1LL*res)%M))%M;
	else
		return (res*1LL*res)%M;
}


/*  ===========================  Iterative Approach ====================== */
int bin_expo_iter(int a, int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=(res*1LL*a)%M;

		a=(a*1LL*a)%M;
		b>>=1;
	}
	return res;
}


/* =========================== When multiplication exceeds long long range =============== */
// =========================== Modulo is in range of Long Long ==========================
long long bin_mult(long long a, long long b)
{
	long long ans=0;
	while(b)
	{
		if(b&1)
			ans=(ans+a)%MM;      // 3(11)
                                 // 3(1101)
		a=(a+a)%MM;              
		b>>=1;
	}
	return ans;
}


long long bin_expo_iter_long(long long a, long long b)
{
	long long ans=1;
	while(b>0)
	{
		if(b&1)
			ans=bin_mult(ans, a);
		b>>=1;
		a=bin_mult(a, a);
	}
	return ans;
}


/* ========================   When b is given interms of c^d ================  */
int bin_expo_iter_long_b(int a, long long b, int m)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=(res*1LL*a)%m;

		a=(a*1LL*a)%m;
		b>>=1;
	}
	return res;
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

	int a, b, e;
	cin>>a>>b>>e;
	cout<<bin_expo_iter(a, b)<<endl;
	cout<<bin_expo_recurr(a, b)<<endl;
	long long c = (long long)a;
	long long d = (long long)b;
	cout<<bin_expo_iter_long(c, d)<<endl;
	
	cout<<bin_expo_iter_long_b(a, bin_expo_iter_long_b(b, e, M-1), M)<<endl;


	return 0;
}