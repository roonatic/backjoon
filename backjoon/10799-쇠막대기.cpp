#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack<char> pipe;
	string s;
	int cnt = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			pipe.push(s[i]);
		else if (s[i] == ')')
		{
			pipe.pop();
			if (s[i - 1] == '(')
				cnt += pipe.size();
			else if (s[i - 1] == ')')
				cnt++;
		}
	}
	cout << cnt;
}