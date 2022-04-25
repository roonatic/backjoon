#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int f = 1;
	for (int i = 2; i <= n; i++)
		f *= i;

	string fct = to_string(f);
	int ans = 0;
	for (int i = fct.size() - 1; i >= 0; i--)
	{
		if (fct[i] == 48)
			ans++;
		else
			break;
	}

	cout << ans;
}