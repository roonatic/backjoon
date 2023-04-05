#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int a;
	int b;
	int answer = 0;
	vector<int> A;
	vector<int> B;
	cin >> n;

	int k = n;
	while (k--)
	{
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());
	k = n;
	while (k--)
	{
		cin >> b;
		B.push_back(b);
	}
	sort(B.begin(), B.end(), greater<int>());

	for (int i = 0; i < n; i++)
	{
		answer += (A[i] * B[i]);
	}

	cout << answer;

	return 0;
}