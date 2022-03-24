//10866 - 덱
//STL deque 사용 안하고 list로 문제풀이
#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
	list<int> deque;
	int n;
	int m;
	cin >> n;
	while (n--)
	{
		string cmd;
		int print = 0;
		cin >> cmd;

		if (cmd.compare("push_front") == 0)
		{
			cin >> m;
			deque.push_front(m);
		}
		else if (cmd.compare("push_back") == 0) 
		{
			cin >> m;
			deque.push_back(m);
		}
		else if (cmd.compare("pop_front") == 0)
		{
			if (deque.empty())
				cout << -1 << endl;
			else
			{
				print = deque.front();
				deque.pop_front();
				cout << print << endl;
			}
		}
		else if (cmd.compare("pop_back") == 0)
		{
			if (deque.empty())
				cout << -1 << endl;
			else
			{
				print = deque.back();
				deque.pop_back();
				cout << print << endl;
			}
		}
		else if (cmd.compare("size") == 0)
		{
			cout << deque.size() << endl;
		}
		else if (cmd.compare("empty") == 0)
		{
			if (deque.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (cmd.compare("front") == 0)
		{
			if (deque.empty())
				cout << -1 << endl;
			else
				cout << deque.front() << endl;
		}
		else if (cmd.compare("back") == 0)
		{
			if (deque.empty())
				cout << -1 << endl;
			else
				cout << deque.back() << endl;
		}
	}


}