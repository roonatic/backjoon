#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	queue<int> card;
	cin >> n;

	for (int i = 1; i <= n; i++)
		card.push(i);

	while (!(card.size() == 1))
	{
		card.pop();
		if (card.size() == 1)
			break;
		else
		{
			int tmpt = card.front();
			card.pop();
			card.push(tmpt);
		}
	}

	cout << card.front();

}