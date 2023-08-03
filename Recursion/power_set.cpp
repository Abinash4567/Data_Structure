#include <iostream>
#include <vector>
	using namespace std;

void power_set(string str, string str1, vector<string> &ans, int index)
{
	if(index>=str.size())
	{
		ans.push_back(str1);
		return;
	}

	power_set(str, str1, ans, index+1);
	power_set(str, str1+str[index], ans, index+1);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<string> ans;
	power_set("abc", "", ans, 0);

	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<endl;
	return 0;
}