#include <iostream>
   using namespace std;

/* Euler’s Totient Function
   Extended Euclidean algorithm also finds integer coefficients x and y such that: 
         ax + by = gcd(a, b) 

    Input: a = 30, b = 20
    Output: gcd = 10, x = 1, y = -1
      (Note that 30*1 + 20*(-1) = 10)      

             y = x1 – ⌊a/b⌋ * y1
                x = y1                            */

struct triplet
{
   int x, y, gcd;
 };

triplet extended_euclid(int a, int b)
{
	if(b==0)
	{
		triplet ans;
		ans.x=1;
		ans.y=0;
		ans.gcd=a;
		return ans;
	}

	triplet small_ans=extended_euclid(b, a%b);
	triplet ans;
	ans.gcd=small_ans.gcd;
	ans.x=small_ans.y;
	ans.y=small_ans.x-(a/b)*small_ans.y;
	return ans;
}

int main()
{
	int a, b;
	cin>>a>>b;

	triplet ans = extended_euclid(a, b);
	cout<<ans.x<<"\t"<<ans.y<<"\t"<<ans.gcd;

	return 0;
}