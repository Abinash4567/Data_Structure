#include <iostream>
	using namespace std;

void Tower_of_Hanoi(int n, char src, char aux, char dest)
{
	if(n==0)
	{
		return;
	}
	Tower_of_Hanoi(n-1, src, dest, aux);
	cout<<"Move "<<n<<" from "<<src<<" to "<<dest<<endl;
	// Tower_of_Hanoi(1, src, aux, dest);
	Tower_of_Hanoi(n-1, aux, src, dest);
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


	int n;
	cin>>n;

	Tower_of_Hanoi(n, 'A', 'B', 'C');
	return 0;
}