#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	stack<char> r;
	string str;
	getline(cin, str);

	string tmpt = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 60)
		{
			do
			{
				tmpt += str[i];
				i++;
				if (str[i] == 62)
				{
					tmpt += str[i];
					cout << tmpt;
					tmpt = "";
					break;
				}
			} while (!(str[i] == 62));
		}
		else if (/*str[i] >= 48 && str[i] <= 57 &&*/ str[i] >= 97 && str[i] <= 122)
		{
			while ((!(str[i] == 32)) || (!(str[i] == 60)))
			{
				if (str[i] == 32 || str[i] == 60)
				{
					while (!r.empty())
					{
						cout << r.top();
						r.pop();
					}
					if (i == str.size())
						break;
					else
					{ 
						i--;
						break;
					}
				}
				else
				{
					r.push(str[i]);
					i++;
				}
			}
		}
		else if (str[i] == 32)
		{
			if (i != str.size())
				cout << ' ';
			else
				break;
		}
	}
}