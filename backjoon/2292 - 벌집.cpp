#include <iostream>
using namespace std;

int hive(int a);

int main() {

	int n;
	cin >> n;
	cout << hive(n);
	return 0;
}

int hive(int a) {

	int tmpt = 1;
	int answer = 1;
	for (int i = 1; tmpt < a; i++) {
		tmpt += i * 6;
		answer++;
	}

	return answer;
}