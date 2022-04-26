#include <iostream>
#include <string>
using namespace std;

int main()
{
	int ans = 0;
	int n;
	cin >> n;

	if (n == 0)
		ans = 0;
	else
	{
		int f = 1;
		for (int i = 2; i <= n; i++)
			f *= i;

		string fct = to_string(f);
		for (int i = fct.size() - 1; i >= 0; i--)
		{
			if (fct[i] == 48)
				ans++;
			else
				break;
		}
	}
	cout << ans;
}