#include <iostream>
     using namespace std;

// ========================= Subset generation =======================
void Bitwise_subset(string str)
{
	int n=str.size();

	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i & (1<<j))
				cout<<str[j];
		}
		cout<<endl;
	}
}

int main()
{
	string str;
	cin>>str;

	Bitwise_subset(str);
	return 0;
}