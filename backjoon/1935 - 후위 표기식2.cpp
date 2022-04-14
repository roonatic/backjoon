#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int n, m;
	string cmd;
	stack<double> num;
	stack<char> cal;
	cin >> n;
	int* arr = new int[n+1];

	cin >> cmd;

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		arr[i] = m;
	}

	double result = 0;
	int j = 0;
	for (int i = 0; i < cmd.size(); i++)
	{
		if (cmd[i] >= 65 && cmd[i] <= 90)
		{
			num.push(arr[j]);
			j++;
		}
		else if (cmd[i] == '+' || cmd[i] == '-')
		{
			if (cal.top() == '*' || cal.top() == '/')
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
		
		if (i == cmd.size() - 1 || (cmd[i] == ))
		{

			while (num.size() != 1 && !cal.empty())
			{
				double num1 = num.top();
				num.pop();
				double num2 = num.top();
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
	}

	printf("%.2f",num.top());
}