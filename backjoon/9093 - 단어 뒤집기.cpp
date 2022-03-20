#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main()
{
	int n;
	cin >> n;
	cin.ignore(); //�Է� ���ۿ� ���๮�ڰ� �����ֱ� ������ ���� Ŭ���� ����

	while(n--)
	{
		string input;
		getline(cin, input);
		stack <char> reverse;

		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == ' ') //������ �����ϸ�
			{
				while (!reverse.empty()) //���� ���
				{
					cout << reverse.top(); //���� �� ���� �ܾ ����ϰ�
					reverse.pop(); //�ܾ� ����
				}
				cout << ' '; //���� ���� ���
			}
			else if (i == input.size() - 1) //������ �� �ܾ��
			{
				reverse.push(input[i]); //�ش� �ܾ ���� ���ÿ� �߰��� ��
				while (!reverse.empty()) //������ ����������� �� ���� �ܾ���� �Է� = �ܾ���� ��������
				{
					cout << reverse.top(); 
					reverse.pop();
				}
				break;
			}
			else
			{
				reverse.push(input[i]);
			}
		}

		cout << endl;
	}
}