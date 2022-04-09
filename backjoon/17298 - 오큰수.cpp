#include <iostream>
#include <stack>
using namespace std;


int main()
{
	int n;
	cin >> n;
	
	int m;

	int* arr = new int[n];
	stack<int> NGE;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		arr[i] = m;
	}

	int* ans = new int[n];
	for (int i = n - 1; i >= 0; i--)
	{
		while (!NGE.empty() && NGE.top() <= arr[i])
			NGE.pop();
	
		if (NGE.empty())
			ans[i] = -1;
		else
			ans[i] = NGE.top();

		NGE.push(arr[i]);
	}

	for (int i = 0; i < n; i++)
			cout << ans[i] << ' ';

}