//우선순위 큐 문제
//1966 - 프린터 큐
//우선순위 큐 STL priority_queue
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int cmd; //테스트케이스의 수
	cin >> cmd;
	while (cmd--)
	{
		//초기화
		queue<pair<int, int>> printer; //문서 큐
		priority_queue<int> prior; //인쇄 순서 우선순위 큐

		int n; //문서의 개수
		int m; //몇번째로 인쇄되었는지 궁금한 문서
		int printcnt = 0; // 몇 번째로 인쇄되었는지
		cin >> n >> m;
		
		for(int i=0;i<n;i++)
		{
			int doc;
			cin >> doc;
			printer.push(make_pair(i, doc)); //(n번째, 문서)
			prior.push(doc); //우선순위 삽입
		}

		while (!printer.empty())
		{
			int index = printer.front().first; //(n번째)
			int priority = printer.front().second; //문서

			if (prior.top() > priority) //우선순위가 높으면
			{
				printer.push(printer.front()); //앞에 있던 것을 뒤에 삽입
				printer.pop(); //삽입 후에 앞의 원소를 빼줌
			}
			else
			{
				printcnt++;
				printer.pop();
				prior.pop();

				if (index == m) //만약 찾으려고 했던 문서 발견시
				{
					cout << printcnt << endl; //출력
					break;
				}
			}
		}

		
	}
}