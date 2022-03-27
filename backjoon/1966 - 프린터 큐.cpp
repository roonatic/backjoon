//�켱���� ť ����
//1966 - ������ ť
//�켱���� ť STL priority_queue
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int cmd; //�׽�Ʈ���̽��� ��
	cin >> cmd;
	while (cmd--)
	{
		//�ʱ�ȭ
		queue<pair<int, int>> printer; //���� ť
		priority_queue<int> prior; //�μ� ���� �켱���� ť

		int n; //������ ����
		int m; //���°�� �μ�Ǿ����� �ñ��� ����
		int printcnt = 0; // �� ��°�� �μ�Ǿ�����
		cin >> n >> m;
		
		for(int i=0;i<n;i++)
		{
			int doc;
			cin >> doc;
			printer.push(make_pair(i, doc)); //(n��°, ����)
			prior.push(doc); //�켱���� ����
		}

		while (!printer.empty())
		{
			int index = printer.front().first; //(n��°)
			int priority = printer.front().second; //����

			if (prior.top() > priority) //�켱������ ������
			{
				printer.push(printer.front()); //�տ� �ִ� ���� �ڿ� ����
				printer.pop(); //���� �Ŀ� ���� ���Ҹ� ����
			}
			else
			{
				printcnt++;
				printer.pop();
				prior.pop();

				if (index == m) //���� ã������ �ߴ� ���� �߽߰�
				{
					cout << printcnt << endl; //���
					break;
				}
			}
		}

		
	}
}