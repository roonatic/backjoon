#include <iostream>
#include <string>
using namespace std;

int main() 
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;


	int queue[10000] = { 0, };
	int i = 0;
	int j = 0;
	int x;
	while (n--) 
	{
		string tmpt = "";
		cin >> tmpt;

		int size = i - j;

		if (tmpt == "push")
		{
			cin >> x;
			queue[i] = x;
			i++;
		}
		else if (tmpt == "pop")
		{
			if (size == 0)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << queue[j] << "\n";
				j++;
			}
		}
		else if (tmpt == "size")
		{
			cout << size << "\n";
		}
		else if (tmpt == "empty")
		{
			if (size == 0)
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else if (tmpt == "front")
		{
			if (size == 0)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << queue[j] << "\n";
			}
			
		}
		else if (tmpt == "back")
		{
			if (size == 0)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << queue[i-1] << "\n";
			}
		}
	}
}