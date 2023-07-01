#include <iostream>
#include <vector>
#include <string>
    using namespace std;

void Possibilities_keypad(string digit, int index, string mapping[], vector<string> &ans, string str)
{
	if(index==digit.size())
	{
		ans.push_back(str);
		return;
	}

	int num=digit[index]-'0';
	string key=mapping[num];

	for(int i=0;i<key.size();i++)
	{
		str.push_back(key[i]);
		Possibilities_keypad(digit, index+1, mapping, ans, str);
		str.pop_back();
	}
}

int main()
{
	string digit;
	cin>>digit;

	string str="";
	vector<string> ans;
	string mapping[]={"", "",  "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

	Possibilities_keypad(digit, 0, mapping, ans, str);

	for (int i = 0; i < ans.size(); ++i)
		cout<<ans[i];
	return 0;
}