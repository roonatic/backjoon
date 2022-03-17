#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	int n; //정점의 개수
	int m; //간선의 개수
	int v; //탐색 시작할 정점 번호

	cin >> n >> m >> v;
	vector<int>* graph = new vector<int>[n+1];
	bool* visited = new bool[n+1];

	//그래프 구현
	int a;
	int b;
	while (m--)
	{
		cin >> a >> b;
		graph[a].push_back(b);
	}


	
	//DFS 구현 - Stack 사용
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

	//BFS 구현 - Queue 사용
	//앞에서 쓴 visited 초기화
	for (int i = 0; i < n+1; i++)
		visited[i] = false;

	queue<int> BFS;
	BFS.push(v);
	visited[v] = true;
	while (!BFS.empty())
	{
		int cur = BFS.front();
		BFS.pop(); //방문했으므로 true로
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