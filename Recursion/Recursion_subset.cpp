#include <iostream>
#include <string>
#include <vector>
    using namespace std;


void Recursion_subset(string str, vector<string> &ans, int index, string curr)
{
	if(index==str.size())
	{
		ans.push_back(curr);
		return;
	}

	Recursion_subset(str, ans, index+1, curr);     //exclude
	curr.push_back(str[index]);
	Recursion_subset(str, ans, index+1, curr);     //include
}

int main()
{
	string str;
	cin>>str;

	string curr="";
	vector<string> ans;
	Recursion_subset(str, ans, 0, curr);

	for(auto i:ans)
		cout<<i<<endl;

	return 0;
}