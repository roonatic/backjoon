#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int m;

	int* arr = new int[n]; //�Է¹迭 �����Ҵ�
	stack<int> NGE; //����� ���� ����
	for (int i = 0; i < n; i++) //���� �迭�� �Է°� �߰�
	{
		cin >> m;
		arr[i] = m;
	}

	int* ans = new int[n]; //���� �迭 �����Ҵ�
	for (int i = n - 1; i >= 0; i--) //�Է¹迭�� �� �ڿ������� ����
	{
		while (!NGE.empty() && NGE.top() <= arr[i]) // ��� ������ ������� �ʰ� top�� ���ذ����� ������
			NGE.pop(); //top�� ���� 
	
		if (NGE.empty()) //���۰��� �� �����ʿ� ������ �� �̻� �������� ���� ������
			ans[i] = -1; //�ش簪�� ������ -1�� �ȴ�
		else
			ans[i] = NGE.top(); // top�� ���ذ����� ũ�� ������ top 

		NGE.push(arr[i]); //���ذ��� �־��༭ �տ��� ����ϱ� ���� ���� ����
	}

	for (int i = 0; i < n; i++) //���� ���
			cout << ans[i] << ' ';

}