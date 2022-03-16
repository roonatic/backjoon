#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int cn = 0;
	int mn = 0;
	int n = 0;
	int m = 0;

	vector<int> card;
	vector<int> mine;
	vector<int> ans;

	//���� ������ �ִ� ī�� �Է�
	cin >> mn;
	while (mn--)
	{
		cin >> n;
		mine.push_back(n);
	}

	//ī���� ��� �Է�
	cin >> cn;
	while (cn--)
	{
		cin >> m;
		card.push_back(m);
	}

	//���� ������ �ִ� ī�带 ������������ ����
	sort(mine.begin(), mine.end());

	//����Ž�� ����
	for (int i = 0; i < card.size(); i++)
	{
		int left = 0;
		int right = mine.size() - 1;
		int cnt = 0; //�ش� ī�带 ���� �ִ��� ���� ���� ������ �Ǵ��ϱ� ���� ī����
		//����Ž��
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (card[i] < mine[mid]) //ī�尡 ���Ϸ��� ī�庸�� ������
			{
				right = mid - 1; //right ����
			}
			else if (card[i] > mine[mid]) //ī�尡 ���Ϸ��� ī�庸�� ũ��
			{
				left = mid + 1; //left ����
			}
			else if (card[i] == mine[mid]) //���Ϸ��� ī��� ������
			{
				ans.push_back(1); //���信 1�� Ǫ��
				cnt = 1; //ī���͸� 1�� �ٲ���
				break;
			}
		}
		if (cnt == 0) //���� ��ġ�ϴ� ī�带 ã�� ��������
			ans.push_back(0); // ���信 0�� Ǫ��
	}

	//���� ���
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";


}