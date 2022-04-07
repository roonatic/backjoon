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
		if (str[i] == 60) // <이면
		{
			do
			{
				tmpt += str[i];
				i++;
			} while (!(str[i] == 62)); // >일때까지
			if (str[i] == 62)
			{
				tmpt += str[i];
				cout << tmpt;
				tmpt = "";
			}
		}
		else if ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 97 && str[i] <= 122))
		{	
			while ((str[i] != 32) && (str[i] != 60))
			{
				if (i == str.size())
					break;
				else
				{
					r.push(str[i]);
					i++;
				}
			}
			while (!r.empty())
			{
				cout << r.top();
				r.pop();
			}
			if (str[i] == 60 || str[i] == 32)
			{
				if (str[i] == 32)
					cout << ' ';
				else
					i--;
			}
		}
	}
}