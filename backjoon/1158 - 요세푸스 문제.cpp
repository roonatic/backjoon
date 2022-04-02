//1158 - �似Ǫ�� ����
//ť�� ���
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> answer;
	int n; 
	int k;

	cin >> n >> k;

	while (n-- > 0)
	{
		queue<int> con;
		for (int i = 1; i <= n; i++)
			con.push(i);

		if (k == con.front())
		{
			answer.push(con.front());
			con.pop();
			break;
		}
		else
		{
			int temp = con.front();
			con.pop();
			con.push(temp);
		}
	}

	cout << "<";
	while (!answer.empty())
	{
		if (answer.size() == 1)
			cout << answer.front() << ">";
		else
		{
			cout << answer.front() << ", ";
			answer.pop();
		}
	}

}