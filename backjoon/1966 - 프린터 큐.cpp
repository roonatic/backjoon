//
//우선순위 큐 문제
//1966 - 프린터 큐
//우선순위 큐 STL priority_queue
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> printer;
	int cmd; //테스트케이스의 수
	cin >> cmd;
	while (cmd--)
	{
		int n; //문서의 개수
		int m; //몇번째로 인쇄되었는지 궁금한 문서
		int target;
		cin >> n >> m;
		while (n--)
		{
			int doc;
			cin >> doc;
			printer.push(doc);
			if (printer.size() == m)
				target = printer.back();
		}

		if (m == 0)
			target = printer.front();


		
	}
}