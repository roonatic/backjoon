#include <iostream>
#include <stack>
using namespace std;

#define MAX 1000001

int main()
{
	int n, m;
	cin >> n;

	int* arr = new int[n]; //�Է� �迭 �����Ҵ�
	int* ans = new int[n]; //���� �迭 �����Ҵ�
	int cnt[MAX] = { 0, }; //���� Ƚ���� ����ϴ� �迭
	stack<int> NGF; //����ū���� ����ϱ� ���� ����

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		arr[i] = m;
		cnt[m] += 1; //�� ���ڰ� �󸶳� �����ߴ°�
	}

	for (int i = n-1; i >= 0; i--) //�Է¹迭�� �� �ڿ������� ����
	{
		int tmpt = arr[i]; 
		while (!NGF.empty() && cnt[NGF.top()] <= cnt[tmpt]) //��� ������ ������� �ʰ���� Ƚ���� top���� ũ��
			NGF.pop(); //pop

		if (NGF.empty()) //��� ������ ��������� �� �������̶�� ���̹Ƿ�
			ans[i] = -1;  //-1 ���
		else
			ans[i] = NGF.top(); //�ش� ����ū�� ã��

		NGF.push(tmpt);
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
}