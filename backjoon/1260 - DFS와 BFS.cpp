#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int n; //������ ����
	int m; //������ ����
	int v; //Ž�� ������ ���� ��ȣ

	cin >> n >> m >> v;
	vector<int>* graph = new vector<int>[n+1]; //�׷���
	bool* visited = new bool[n+1]; //�湮�ߴ��� üũ�ϱ� ���� �迭

	//�湮 üũ �迭 �ʱ�ȭ
	for (int i = 0; i < n + 1; i++)
		visited[i] = false;

	//�׷��� ����
	int a;
	int b;
	while (m--)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a); //����� �׷����� ������ �ݴ��� ��쵵 �߰�
	}

	//������������ ����
	for (int i = 0; i < n+1; i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
			sort(graph[i].begin(), graph[i].end());
	}

	//DFS ���� - Stack ���
	stack<int> DFS;
	DFS.push(v);
	visited[v] = true;
	cout << DFS.top() << ' ';

	while (!DFS.empty())
	{
		int cur = DFS.top(); //���� ��ġ
		DFS.pop();
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int now = graph[cur][i];
			if (!visited[now])
			{
				cout << now << ' ';
				DFS.push(cur);
				DFS.push(now);
				visited[now] = true;
				break;
			}
		}
	}

	cout << endl;

	//BFS ���� - Queue ���
	//�տ��� �� visited �ʱ�ȭ
	for (int i = 0; i < n+1; i++)
		visited[i] = false;

	queue<int> BFS;
	BFS.push(v);
	visited[v] = true;
	cout << BFS.front() << ' ';
	while (!BFS.empty())
	{
		int cur = BFS.front();
		BFS.pop(); 
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int now = graph[cur][i];
			if (!visited[now]) //�� ���� �湮���� �ʾ��� ��쿡
			{
				cout << now << ' ';
				BFS.push(now);
				visited[now] = true; //�湮�����Ƿ� true��
			}
		}
	}

}