#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;

	while (n--)
	{
		queue<int> printer;
		int print;
		int what;
		int cnt = 0;
		int cmp;
		cin >> print >> what;
		
		while (!cin.eof())
		{
			int doc;
			cin >> doc;
			printer.push(doc);
			cnt++;
			if (cnt == what)
				cmp = what;
		}
		

		
	}
}