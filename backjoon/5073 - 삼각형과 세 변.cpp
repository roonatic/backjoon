#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string check(int a, int b, int c);

int main() {

	int a, b, c;

	while (1) {
		cin >> a >> b >> c;
		if (a == 0)
			break;
		else
			cout << check(a, b, c) << "\n";
	};

	return 0;
}

string check(int a, int b, int c) {
	vector<int> triangle;
	string answer = "";

	triangle.push_back(a);
	triangle.push_back(b);
	triangle.push_back(c);

	sort(triangle.begin(), triangle.end());

	if (triangle[0] + triangle[1] <= triangle[2])
		answer = "Invalid";
	else if (triangle[0] == triangle[1] && triangle[1] == triangle[2])
		answer = "Equilateral";
	else if (triangle[0] == triangle[1] || triangle[1] == triangle[2])
		answer = "Isosceles";
	else
		answer = "Scalene";

	return answer;

}