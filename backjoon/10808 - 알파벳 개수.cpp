#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int chk[27] = {0, };

	cin >> s;
	for (int i = 0; i < s.size(); i++)
		chk[s[i] - 97]++;

	for (int i = 0; i < 26; i++)
		cout << chk[i] << ' ';
}