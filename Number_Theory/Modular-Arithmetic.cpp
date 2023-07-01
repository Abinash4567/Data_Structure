/*   Number of ways to distribute N chlidren among K chocolate:
            nCr=n!/(n-r!)*r!                                       */

#include <iostream>
#include <climits>
   using namespace std;

const int  M = INT_MAX;
const int N = 1000;
int fact[N];

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

	fact[0]=1;
	for(int i=1;i<N;i++)
		fact[i]=(fact[i-1]*i)%M; 

	for(int i=1;i<N;i++)
		cout<<fact[i]<<endl;

	return 0;
}