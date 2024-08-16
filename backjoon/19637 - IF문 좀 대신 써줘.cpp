#include <iostream>
#include <vector>
using namespace std;

/* �̺�Ž�� ���� ���� */
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	vector<string> title;
	vector<int> stat;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string t;
		int s;
		cin >> t >> s;
		title.push_back(t);
		stat.push_back(s);
	}

	while (m--)
	{
		int start = 0;
		int end = stat.size() - 1;
		int mid = 0;

		int test;
		cin >> test;
		while (start <= end)
		{
			mid = (start + end) / 2;

			if (stat[mid] >= test)
				end = mid - 1;
			else
				start = mid + 1;
		}

		if (test > stat[mid])
			cout << title[mid + 1] << "\n";
		else
			cout << title[mid] << "\n";
	}

	return 0;
}

/* lower_bound ���*/
/*
#include <map>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;

	map<double, string> title;
	cin >> n >> m;
	while (n--)
	{
		string t;
		double stat;

		pair<double, string> input;

		cin >> t >> stat;
		input = make_pair(stat, t);
		title.insert(input);
	}

	map<double, string>::iterator it;
	while (m--)
	{
		double stat;
		cin >> stat;

		// lower_bound: ã������ key ������ ���ų�
		// �迭 �� ��°�� �����ϴ��� ã�� ����
		it = title.lower_bound(stat);
		cout << it->second << "\n";
	}

	return 0;
}
*/