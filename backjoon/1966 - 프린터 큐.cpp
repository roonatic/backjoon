//
//�켱���� ť ����
//1966 - ������ ť
//�켱���� ť STL priority_queue
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> printer;
	int cmd; //�׽�Ʈ���̽��� ��
	cin >> cmd;
	while (cmd--)
	{
		int n; //������ ����
		int m; //���°�� �μ�Ǿ����� �ñ��� ����
		int target;
		cin >> n >> m;
		while (n--)
		{
			int doc;
			cin >> doc;
			printer.push(doc);
			if (printer.size() == m)
				target = printer.back();
		}

		if (m == 0)
			target = printer.front();


		
	}
}