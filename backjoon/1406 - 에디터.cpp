#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	int m;
	cin >> str;
	cin.ignore();
	stack<char> cmd;

	int cursor = str.size();

	cin >> m;
	while (m--)
	{
		char edit;
		cin >> edit;
		if (edit == 'P')
		{
			string add;
			cin >> add;

			str.insert(cursor, add);
			cursor += 1;
		}
		else if (edit == 'B')
		{
			if (cursor == 0)
				continue;
			else
			{
				str.erase(cursor - 1, 1);
				cursor -= 1;
			}
		}
		else if (edit == 'D')
		{
			if (cursor != str.size())
				cursor += 1;
		}
		else if (edit == 'L')
		{
			if (cursor != 0)
				cursor -= 1;
		}
		//cout << str;
		cmd.push(edit);
	}

	cout << str;
}