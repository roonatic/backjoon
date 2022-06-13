#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int tx = 1, ty = 1;
		int cnt = 1;


		while (1)
		{
			if (tx < M)
				tx++;
			else
				tx = 1;

			if (ty < N)
				ty++;
			else
				ty = 1;

			cnt++;

			if ((x == tx) && (y == ty))
				break;
			else if ((M == tx) && (N == ty))
			{
				cnt = -1;
				break;
			}
		}
		cout << cnt << "\n";
	}

}