#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	stack<char> postfix;
	string ans = "";
	
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 65 && s[i] <= 90)
			ans += s[i];
		else if (s[i] == 40)
			postfix.push(s[i]);
		else if (s[i] == 43 || s[i] == 45)
		{
			if (postfix.top() == 42 || postfix.top() == 47)
			{
				ans += postfix.top();
				postfix.pop();
				postfix.push(s[i]);
			}
			else
				postfix.push(s[i]);
		}
		else if (s[i] == 42 || s[i] == 47)
			postfix.push(s[i]);
		else if (s[i] == 41)
		{
			while (postfix.top() != 40)
			{
				ans += postfix.top();
				postfix.pop();
			}
			postfix.pop();
		}

		if (i == s.size() - 1)
		{
			while (!postfix.empty())
			{
				ans += postfix.top();
				postfix.pop();
			}
		}
	}
	
	cout << ans;
}