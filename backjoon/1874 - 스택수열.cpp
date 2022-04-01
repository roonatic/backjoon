#include <iostream>
#include <stack>
#include <deque>
using namespace std;

int main()
{
	deque<int> arr;
	bool t = true;
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		arr.push_back(i);

	stack<int> test;
	deque<char>cmd;
	int chk = 1;
	int m = n;
	while (n--)
	{
		int num;
		cin >> num;
		while (1)
		{
			if (!test.empty() && num == test.top())
			{
				test.pop();
				cmd.push_back('-');
				break;
			}

			if (chk > m && !test.empty())
			{
				t = false;
				break;
			}
			test.push(chk);
			cmd.push_back('+');
			chk++;
		}
	}

	if (t == true)
	{
		for (int i = 0; i < cmd.size(); i++)
			cout << cmd.at(i) << endl;
	}
	else
		cout << "NO";

	
}
