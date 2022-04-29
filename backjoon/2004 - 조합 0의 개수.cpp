#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	int m;

	cin >> n >> m;

	int a = n - m + 1;
	for (int i = a + 1; i <= n; i++)
		a *= i;

	int b = 1;
	for (int i = 2; i <= m; i++)
		b *= i;

	int comb = a / b;

	string str = to_string(comb);
	int ans = 0;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i] == 48)
			ans++;
		else
			break;
	}

	cout << ans;
}