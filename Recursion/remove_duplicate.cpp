#include <iostream>
	using namespace std;

string remove_duplicate(string str)
{
	if(str.size()==0)
		return "";

	char ch = str[0];

	string s = remove_duplicate(str.substr(1));

	if(ch==s[0])
		return s;
	else
		return ch+s;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cout<<remove_duplicate("aaaabbbbbddddyyy");
	return 0;
}