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
		if (s[i] >= 65 && s[i] <= 90) //���ĺ�
			ans += s[i];
		else if (s[i] == 40) // (
			postfix.push(s[i]);
		else if (s[i] == 43 || s[i] == 45) //+ �Ǵ� -�� ��
		{
			while(!postfix.empty() && postfix.top() != 40) // )�� �ƴϸ�
			{
				ans += postfix.top();
				postfix.pop();
			}
			postfix.push(s[i]);
		}
		else if (s[i] == 42 || s[i] == 47) // * �Ǵ� /�� ��
		{
			if (postfix.empty() || postfix.top() == 43 || postfix.top() == 45)
				postfix.push(s[i]);
			else if(postfix.top() == 42 || postfix.top() == 47)
			{
				ans += s[i];
				ans += postfix.top();
				postfix.pop();
			}

		}
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

/*
�ݷ�)

input: A+((B*C)*D)*E
output: ABC*D*+E*
answer: ABC*D*E*+

&& || �켱���� �����ؾ�
*/