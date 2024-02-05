#include <iostream>
    using namespace std;

/* ===================== Calculation of nCr  ================================*/
/* ===================== n!/r!*(n-r)! =======================================*/
// ===================== Feramt Little Theorem ================
int inv_bin_exp(int a, int b, int m)
{
	a = a % m;
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

int nCrModPermat(int n, int r, int m)
{
	if(n<r)
		return 0;
	if(r==0)
		return 1;

	int fact[n+1];
	fact[0]=1;
	for(int i=1;i<=n;i++)
		fact[i]=(fact[i-1]*1LL*i)%m;

	return (((fact[n]*inv_bin_exp(fact[r], m-2, m))%m)*inv_bin_exp(fact[n-r], m-2, m))%m;
}




int main()
{
	int n, r, m;
	cin>>n>>r>>m;

	cout<<nCrModPermat(n, r, m);

	return 0;
}