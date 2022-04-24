#include <iostream>
using namespace std;

int gcd(int a, int b);

int main()
{
	int n;
	cin >> n;

	while(n--)
	{
		int a;
		int b;

		cin >> a >> b;

		int g = gcd(a, b);
		int lcm = g * (a / g) * (b / g);

		cout << lcm << "\n";
	}
}

int gcd(int a, int b)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}