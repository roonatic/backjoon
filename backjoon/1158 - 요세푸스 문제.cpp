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

	queue<int> con;
	for (int i = 1; i <= n; i++)
		con.push(i);

	int cnt = n - 1;
	cout << "<";
	while (cnt--)
	{
			for (int i = 0; i < k - 1; i++)
			{
				con.push(con.front());
				con.pop();
			}
			cout << con.front() << ", ";
			con.pop();
	}
	cout << con.front() << ">";
}