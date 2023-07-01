#include <iostream>
#include <vector>
#include <climits>
	using namespace std;

int median_arrays(vector<int> &arr1, vector<int> &arr2)
{
	int n1=arr1.size();
	int n2=arr2.size();

	if(n1>n2)
		return median_arrays(arr2, arr1);

	int lo=0, hi=n1;

	while(lo<=hi)
	{
		int m1=(lo+hi)/2;
		int m2=((n1+n2+1)/2)-m1;

		int l1=(m1==0)?INT_MIN:arr1[m1-1];
		int r1=(m1==n1)?INT_MAX:arr1[m1];

		int l2=(m2==0)?INT_MIN:arr2[m2-1];
		int r2=(m2==n2)?INT_MAX:arr2[m2];

		if(l1>r2)
		{
			hi=m1-1;
		}
		else if(l2>r1)
		{
			lo=m1+1;
		}

		else if(l1<=r2 and l2<=r1)
		{
			if((n1+n2)%2!=0)
			{
				return (float)max(l1, l2);
			}
			else
			{
				return (float)(max(l1, l2)+min(r1,  r2))/2.00;
			}
		}

	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    vector<int> arr1{2, 3, 5, 8};
    vector<int> arr2{10, 12, 14, 16, 18, 20};

    cout<<median_arrays(arr1, arr2);

	return 0;
}