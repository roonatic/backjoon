#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	int m;
	list<char> word;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
		word.push_back(str[i]);

	auto cursor = word.end();

	cin >> m;
	while (m--)
	{
		char edit;
		cin >> edit;
		if (edit == 'P')
		{
			char add;
			cin >> add;

			word.insert(cursor, add);
		}
		else if (edit == 'B')
		{
			if (cursor != word.begin())
				cursor = word.erase(--cursor);
		}
		else if (edit == 'D')
		{
			if (cursor != word.end())
				cursor++;
		}
		else if (edit == 'L')
		{
			if (cursor != word.begin())
				cursor --;
		}
	}

	for (cursor = word.begin(); cursor != word.end(); cursor++)
		cout << *cursor;

		
}