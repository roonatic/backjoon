#include <iostream>
#include <stack>
#include <string>
using namespace std;

void test(string example);

int main()
{
		string input;
		while (!cin.eof())
		{
			getline(cin, input);
			if (input.compare(".") != 0)
				test(input);
			else
				break;
		}
}

void test(string example)
{
	stack<char> t;

	for (int i = 0; i < example.size(); i++)
	{
		if (example[i] == '(' || example[i] == '[')
			t.push(example[i]);
		else if (example[i] == ')')
		{
			if (!t.empty())
			{
				if (t.top() == '(')
					t.pop();
				else
				{
					cout << "no" << endl;
					t.push('N');
					break;
				}
			}
			else
			{
				cout << "no" << endl;
				t.push('N');
				break;
			}


		}
		else if (example[i] == ']')
		{
			if (!t.empty())
			{
				if (t.top() == '[')
					t.pop();
				else
				{
					cout << "no" << endl;
					t.push('N');
					break;
				}
			}
			else
			{
				cout << "no" << endl;
				t.push('N');
				break;
			}
		}
	}

	if (t.empty())
		cout << "yes" << endl;
}