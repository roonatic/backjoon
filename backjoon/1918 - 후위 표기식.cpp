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
	bool flag = false;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 40)// ( �����̸�
		{
		/*
			while (!postfix.empty())
			{
				ans += postfix.top();
				postfix.pop();
			}*/
			flag = true;
		}
		else if (s[i] == 41) // )�� ������
		{
			flag = false;
			while (!postfix.empty())
			{
				ans += postfix.top();
				postfix.pop();
			}
		}
		else if (s[i] >= 65 && s[i] <= 90) // ���ĺ��̸�
			ans += s[i];
		else if (s[i] == 43 || s[i] == 45) // + �Ǵ� -
		{
			if (!postfix.empty() && (postfix.top() == 42 || postfix.top() == 47))
			{
				if (flag == true)
					postfix.push(s[i]);
				else
				{
					char tmpt = postfix.top();
					postfix.pop();
					postfix.push(s[i]);
					postfix.push(tmpt);
				}
			}
			else
				postfix.push(s[i]);
		}
		else if (s[i] == 42 || s[i] == 47)
			postfix.push(s[i]);
		if (i == s.size()-1)
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