#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	int t; //�׽�Ʈ���̽� ��
	cin >> t;
	while (t--)
	{
		bool chk = true; //���������� ���������� üũ����
		bool err = false; //���� üũ��
		deque<char> cmd; //��ɾ ���� ��
		deque<int> arr; //���� �迭 ��
		string p; //��ɾ�
		cin >> p;

		for (int i = 0; i < p.size(); i++)
			cmd.push_back(p[i]); //��ɾ� ����

		int n; //�迭�� ����ִ� ����
		cin >> n;

		string array; //string���� ������ �迭 [x1, x2, ...]
		string tmpt = ""; //�ӽ� string: string���� ���� ���� int������ �ٲ��ֱ� ����
		cin >> array;
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] >= 48 && array[i] <= 57) //�����϶�
				tmpt += array[i];
			else if (array[i] == ',' || array[i] == ']')
			{
				if (tmpt == "") //�ƹ��͵� �� ������ �� �迭
					break;
				else
				{
					int temp = stoi(tmpt);
					arr.push_back(temp);
					tmpt = ""; //�ʱ�ȭ
				}
			}
		}

		if (n != arr.size() || (arr.empty() && cmd.front() == 'D'))
			err = true;
		else
		{
			while (!cmd.empty())
			{
				if (cmd.front() == 'R')//R�̸� ������ ��� ����
				{
					if (chk == true) //�������̸�
						chk = false; //������ ������ ǥ��
					else //�������̸�
						chk = true; //����������

					cmd.pop_front();
				}
				else if (cmd.front() == 'D') //D�� �� ���� ���� ����
				{
					if (arr.empty())//�� �� ���Ҹ� �����ؾ��ϴµ� ���� ���������
					{
						err = true;
						break;
					}
					else
					{
						if (chk == true) //�������� ��
						{
							arr.pop_front();
							cmd.pop_front();
						}
						else //�������� ��
						{
							arr.pop_back();
							cmd.pop_front();
						}
					}
				}
			}
		}

		if (arr.empty() && cmd.empty()) //�� �迭�϶�
			cout << "[]" << endl;
		else if (err == true) //���� ���
			cout << "error" << endl;
		else
		{
			if (chk == true) //�������̸�
			{
				cout << "[";
				for (int i = 0; i < arr.size(); i++)
				{
					if (i == arr.size()-1)
						cout << arr.at(i) << "]" << endl;
					else
						cout << arr.at(i) << ",";
				}
			}
			else //���� ���
			{
				cout << "[";
				for (int i = arr.size()-1; i >= 0; i--)
				{
					if (i == 0)
						cout << arr.at(i) << "]" << endl;
					else
						cout << arr.at(i) << ",";
				}
			}
		}
	}
}