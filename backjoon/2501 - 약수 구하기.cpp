#include <iostream>
using namespace std;

int main() 
{
	int n, k;
	int arr[10000] = { 0, };
	
	int m = 2;
	cin >> n >> k;
	
	arr[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			arr[m] = i;
			if (m == k)
				break;
			m++;
		}
	}

		cout << arr[k];
}