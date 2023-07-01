#include <iostream>
#include <string>
#include <vector>
    using namespace std;

void Permutation_string(string str, vector<string> &ans, int index)
{
	if(index==str.size())
	{
		ans.push_back(str);
		return;
	}

	for (int i = index; i < str.size(); ++i)
	{
		swap(str[index], str[i]);
		Permutation_string(str, ans, index+1);
		swap(str[index], str[i]);
	}
}

int main()
{
	string str;
	cin>>str;

	vector<string> ans;

	Permutation_string(str, ans, 0);

	for(string i:ans)
		cout<<i<<endl;
	return 0;
}