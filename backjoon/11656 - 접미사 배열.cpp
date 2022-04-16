#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	deque<char> exe;
	vector<string> ans;

	cin >> s;
	ans.push_back(s);
	for (int i = 0; i < s.size(); i++)
		exe.push_back(s[i]);

	while (!exe.empty())
	{
			string tmpt = "";
			exe.pop_front();
			if (exe.empty())
				break;
			else
			{
				for (int i = 0; i < exe.size(); i++)
					tmpt += exe.at(i);
				ans.push_back(tmpt);
			}
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}