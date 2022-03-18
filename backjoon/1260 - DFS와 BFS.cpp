#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int n; //정점의 개수
	int m; //간선의 개수
	int v; //탐색 시작할 정점 번호

	cin >> n >> m >> v;
	vector<int>* graph = new vector<int>[n+1]; //그래프
	bool* visited = new bool[n+1]; //방문했는지 체크하기 위한 배열

	//방문 체크 배열 초기화
	for (int i = 0; i < n + 1; i++)
		visited[i] = false;

	//그래프 구현
	int a;
	int b;
	while (m--)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a); //양방향 그래프기 때문에 반대의 경우도 추가
	}

	//오름차순으로 정렬
	for (int i = 0; i < n+1; i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
			sort(graph[i].begin(), graph[i].end());
	}

	//DFS 구현 - Stack 사용
	stack<int> DFS;
	DFS.push(v);
	visited[v] = true;
	cout << DFS.top() << ' ';

	while (!DFS.empty())
	{
		int cur = DFS.top(); //현재 위치
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

	//BFS 구현 - Queue 사용
	//앞에서 쓴 visited 초기화
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
			if (!visited[now]) //그 전에 방문하지 않았을 경우에
			{
				cout << now << ' ';
				BFS.push(now);
				visited[now] = true; //방문했으므로 true로
			}
		}
	}

}