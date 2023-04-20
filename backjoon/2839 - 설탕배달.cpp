#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int answer = -1;
	vector<int> temp;
	cin >> n;

	int tmpt = n;

	int i = 1;
	int first = tmpt / 5;
	int second = tmpt / 3;

	if (tmpt % 5 == 0)
		temp.push_back(tmpt / 5);
	if ((tmpt - 5 * first) % 3 == 0)
	{
		second = (tmpt - 5 * first) / 3;
		temp.push_back(first + second);
	}
	if(i * 5 < tmpt)
	{
		while (i*5 < tmpt)
		{
			if ((tmpt - 5 * i) % 3 == 0)
			{
				first = i;
				second = (tmpt - 5 * i) / 3;
				temp.push_back(first + second);
				i = 1;
				break;
			}
			else
				i++;
		}

	}
	if (i * 3 < tmpt)
	{
		while (i * 3 < tmpt)
		{
			if ((tmpt - 3 * i) % 5 == 0)
			{
				first = i;
				second = (tmpt - 3 * i) / 5;
				temp.push_back(first + second);

				break;
			}
			else
				i++;
		}

	}
	if ((tmpt - 3 * second) % 5 == 0)
	{
		first = (tmpt - 3 * second) / 5;
		temp.push_back(first + second);
	}
	if (tmpt % 3 == 0)
		temp.push_back(tmpt / 3);

	sort(temp.begin(), temp.end());

	if (temp.empty())
		cout << answer;
	else
		cout << temp.front();
}