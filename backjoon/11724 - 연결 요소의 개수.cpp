#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
bool visited[1001];

void DFS(int node)
{
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++)
	{
		int next = graph[node][i];
		if (!visited[next])
			DFS(next);
	}
}

int main()
{
	graph.resize(1001);
	int n, m;	// 각각 정점 개수, 간선 개수

	cin >> n >> m;
	int t = m;
	while (t--)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);

	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			DFS(i);
			cnt++;
		}
	}

	cout << cnt;
}