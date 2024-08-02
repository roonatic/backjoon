#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void set(int m);

int main()
{
	int m;
	cin >> m;
	set(m);

	return 0;
}

void set(int m)
{
	vector<int> set;
	while (m--)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		string check;
		int num = 0;
		cin >> check;
		if (check != "all" && check != "empty")
			cin >> num;

		bool chk = true;
		int pos = 0;
		for (int i = 0; i < set.size(); i++)
		{
			if (set[i] == num)
			{
				pos = i;
				chk = false;
				break;
			}
		}

		if (chk == true)
		{
			if (check == "add")
				set.push_back(num);
			else if (check == "check")
				cout << 0 << "\n";
			else if (check == "toggle")
				set.push_back(num);
			else if (check == "all")
			{
				set.clear();
				for (int i = 1; i <= 20; i++)
					set.push_back(i);
			}
			else if (check == "empty")
				set.clear();
		}
		else
		{
			if (check == "remove")
				set.erase(set.begin() + pos);
			else if (check == "check")
				cout << 1 << "\n";
			else if (check == "toggle")
				set.erase(set.begin() + pos);
		}
	}

}