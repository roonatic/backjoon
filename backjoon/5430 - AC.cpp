#include <iostream>
#include <deque>
#include <string>
#include <algorithm> // reverse ��� ����
using namespace std;

int main()
{
	int t; //�׽�Ʈ���̽� ��
	cin >> t;
	while (t--)
	{
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
				if (tmpt != "") //�ӽ� string�� ������ �ƴϸ�
				{
					int temp = stoi(tmpt); //int������ ��ȯ
					arr.push_back(temp); //�迭�� ����
					tmpt = ""; //�ӽ� string �ʱ�ȭ
				}
				else
					break;
			}
		}

		/*
			�Է¹��� �迭 ������� ���� ũ�Ⱑ ���� �ʰų�
			�Է¹��� �迭�� ũ�Ⱑ 0�� ��
		*/
		if (n != arr.size() || arr.empty()) 
		{
			cout << "error" << endl; //���� ȣ��
			break;
		}
		else
		{
			while (!cmd.empty()) //��ɾ� ���� �� ������ �ݺ�
			{
				if (arr.empty() && !cmd.empty()) //��ɾ� �迭�� ������� ������ �迭�� ���������
				{
					cout << "error" << endl; //���� ���
					break;
				}
				else if (cmd.front() == 'R') //��ɾ R�̸� �迭�� ���� ������
				{
					reverse(arr.begin(), arr.end()); //reverse ���
					cmd.pop_front(); //��ɾ ���������Ƿ� ������ ��ɾ� ����
				}
				else if (cmd.front() == 'D') //��ɾ D�� front�� pop
				{
					arr.pop_front();
					cmd.pop_front();
				}
			}

			for (int i = 0; i < arr.size(); i++) //���
			{
				if (i == 0)
					cout << "[" << arr.at(i) << ",";
				else if (arr.size() - 1 == i)
					cout << arr.at(i) << "]" << endl;
				else
					cout << arr.at(i) << ",";
			}
		}
	}
}