#include <iostream>
#include <cmath>
using namespace std;

int zoac(int h, int w, int n, int m);

int main() {
	int h, w, n, m;

	cin >> h >> w >> n >> m;
	cout << zoac(h, w, n, m);

	return 0;
}

int zoac(int h, int w, int n, int m)
{
	int answer = 0;

	int x = (h - 1) / (n + 1) + 1;
	int y = (w - 1) / (m + 1) + 1;

	answer = x * y;

	return answer;
}