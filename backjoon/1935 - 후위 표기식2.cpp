#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int n;
	double m;
	double result = 0;
	string cmd;
	stack<double> num;
	stack<char> cal;
	cin >> n;
	int* arr = new int[n + 1];

	cin >> cmd;

	//A->0 B->1
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		arr[i] = m;
	}

	for (int i = 0; i < cmd.size(); i++)
	{
		if (cmd[i] >= 65 && cmd[i] <= 90) //¾ËÆÄºªÀÌ¸é
		{
			double tmpt = arr[cmd[i] - 65];
			num.push(tmpt);
		}
		else if (cmd[i] == '+' || cmd[i] == '-')
		{
			if (!cal.empty() && (cal.top() == '*' || cal.top() == '/'))
			{
				char temp = cal.top();
				cal.pop();
				cal.push(cmd[i]);
				cal.push(temp);
			}
			else
				cal.push(cmd[i]);
		}
		else if (cmd[i] == '*' || cmd[i] == '/')
			cal.push(cmd[i]);

		while (num.size() != 1 && !cal.empty())
		{
			double num2 = num.top();
			num.pop();
			double num1 = num.top();
			num.pop();

			if (cal.top() == '+')
				result = num1 + num2;
			else if (cal.top() == '-')
				result = num1 - num2;
			else if (cal.top() == '*')
				result = num1 * num2;
			else if (cal.top() == '/')
				result = num1 / num2;

			cal.pop();
			num.push(result);
		}
	}

	printf("%.2lf", num.top());
}