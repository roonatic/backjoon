#include <iostream>
#include <stack>
using namespace std;


int main()
{
	int n;
	cin >> n;
	
	int* arr = new int[n];
	int m;
	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		arr[i] = m;
	}

	for (int i = 1; i <= n; i++)
	{
		stack<int> NGE;
		int test = arr[i];
		for (int j = i+1; j <= n; j++)
		{
			if (test >= arr[j])
				continue;
			else
			{
				NGE.push(arr[j]);
				break;
			}
		}
		
		if (i != n)
		{
			if(!NGE.empty())
				cout << NGE.top() << ' ';
			else
				cout << -1 << ' ';
		}
		else
			cout << -1;

		
	}
}