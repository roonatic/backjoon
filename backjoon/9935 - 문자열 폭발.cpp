#include <iostream>
#include <string>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	string s = "";
	string b = "";

	string answer = "";
	string tmpt = "";
	stack<char> str;
	deque<char> bomb;
	cin >> s;
	cin >> b;

	for (int i = 0; i < s.size(); i++)
	{
		str.push(s[i]);

		if (bomb.size() < b.size())
		{
			bomb.push_back(s[i]);
			tmpt += s[i];
		}
		else if (bomb.size() == b.size())
		{
			tmpt = "";
			bomb.pop_front();
			bomb.push_back(s[i]);

			for (int j = 0; j < bomb.size(); j++)
				tmpt += bomb[j];
		}

		if (tmpt == b)
		{
			tmpt = "";
			while (!bomb.empty())
			{
				bomb.pop_back();
				str.pop();
			}

			if (!str.empty())
			{
				deque<char> temp;
				int t = b.size() - 1;
				while (t--)
				{
					if (!str.empty())
					{
						temp.push_front(str.top());
						str.pop();
					}
				}
				while (!temp.empty())
				{
					tmpt += temp.front();
					str.push(temp.front());
					bomb.push_back(temp.front());
					temp.pop_front();
				}
				
			}
		}
	}

	if (str.empty())
		cout << "FRULA";
	else
	{
		while (!str.empty())
		{
			answer += str.top();
			str.pop();
		}

		reverse(answer.begin(), answer.end());

		cout << answer;
	}
}