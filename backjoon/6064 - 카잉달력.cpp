//분류에는 브루트포스라고 되어있지만 수학을 이용하여 푸는 문제
#include <iostream>
using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for(int k=0;k<t;k++)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int last = lcm(M, N);
		int i = x;
		int j = 0;
		while (i <= last)
		{
			j = i % N;
			if (j == 0)
				j = N;
			if (j == y)
				break;

			i += M;
		}
		if (i > last)
			cout << -1 << "\n";
		else
			cout << i << "\n";
	}

	return 0;
}

int gcd(int a, int b)
{
	if (a < b)
	{
		int tmpt = a;
		a = b;
		b = tmpt;
	}

	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	
	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}