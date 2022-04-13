#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int n, m;
	string cmd;
	stack<int> num;
	stack<char> cal;
	cin >> n;
	int* arr = new int[n];

	cin >> cmd;

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		arr[i] = m;
	}

	int j = 0;
	for (int i = 0; i <= cmd.size(); i++)
	{
		if (cmd[i] >= 65 && cmd[i] <= 90)
		{
			cal.push(cmd[i]);
			j++;
		}
	}
}