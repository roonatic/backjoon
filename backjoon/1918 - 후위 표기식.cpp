/* 후위표기식
문제풀이: +, -, *, /는 top에 연산자보다 우선순위가 낮지 않으면
top출력하고 pop
+ - 은 * / 보다 낮음  */

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
		if (s[i] >= 65 && s[i] <= 90)	// A~Z
			ans += s[i];
		else if (s[i] == 40)	// (
			postfix.push(s[i]);
		else if (s[i] == 43 || s[i] == 45)	// + 또는 -
		{
			while (!postfix.empty() && postfix.top() != 40)	// ( 전까지 스택에 들어가있는 현재보다 우선순위 높거나 같은것들을 다 출력(+-*/)
			{
				ans += postfix.top();
				postfix.pop();
			}
			postfix.push(s[i]);
			
		}
		else if (s[i] == 42 || s[i] == 47)	// * 또는 /
		{
			while (!postfix.empty() && (postfix.top() == 42 || postfix.top() == 47))	// 스택에 들어가있는 현재보다 우선순위 높은 것들을 다 출력(*/)
			{
				ans += postfix.top();
				postfix.pop();
			}
			postfix.push(s[i]);
		}
			
		else if (s[i] == 41)	// )
		{
			while (!postfix.empty() && postfix.top() != 40)	// ( 이전까지 pop
			{
				ans += postfix.top();
				postfix.pop();
			}
			postfix.pop();	// (을 pop해줌
		}
	}

	while (!postfix.empty())	// 스택에 남은 값들을 모두 출력
	{
		ans += postfix.top();
		postfix.pop();
	}

	cout << ans;
}