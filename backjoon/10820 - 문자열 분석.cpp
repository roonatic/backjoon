#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;

	while (getline(cin, s))
	{
		int arr[4] = { 0, };

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 97 && s[i] <= 122)
				arr[0]++;
			else if (s[i] >= 65 && s[i] <= 90)
				arr[1]++;
			else if (s[i] >= 48 && s[i] <= 57)
				arr[2]++;
			else if (s[i] == 32)
				arr[3]++;
		}

		for (int i = 0; i < 4; i++)
			cout << arr[i] << ' ';

		cout << "\n";
	}
}