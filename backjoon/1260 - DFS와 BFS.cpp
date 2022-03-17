#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	int n; //������ ����
	int m; //������ ����
	int v; //Ž�� ������ ���� ��ȣ

	cin >> n >> m >> v;
	vector<int>* graph = new vector<int>[n+1];
	bool* visited = new bool[n+1];

	//�׷��� ����
	int a;
	int b;
	while (m--)
	{
		cin >> a >> b;
		graph[a].push_back(b);
	}


	
	//DFS ���� - Stack ���
	stack<int> DFS;
	DFS.push(v);
	visited[v] = true;
	while (!DFS.empty())
	{
		int cur = DFS.top();
		cout << cur << ' ';
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int now = graph[cur][i];
			if (!visited[now])
			{
				DFS.push(now);
				visited[now] = true;
				break;
			}
		}
	}

	//BFS ���� - Queue ���
	//�տ��� �� visited �ʱ�ȭ
	for (int i = 0; i < n+1; i++)
		visited[i] = false;

	queue<int> BFS;
	BFS.push(v);
	visited[v] = true;
	while (!BFS.empty())
	{
		int cur = BFS.front();
		BFS.pop(); //�湮�����Ƿ� true��
		cout << cur << ' ';
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int now = graph[cur][i];
			if (!visited[now])
			{
				BFS.push(now);
				visited[now] = true;
			}
		}
	}

}