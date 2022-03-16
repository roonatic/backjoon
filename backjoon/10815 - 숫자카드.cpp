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

	//내가 가지고 있는 카드 입력
	cin >> mn;
	while (mn--)
	{
		cin >> n;
		mine.push_back(n);
	}

	//카드의 목록 입력
	cin >> cn;
	while (cn--)
	{
		cin >> m;
		card.push_back(m);
	}

	//내가 가지고 있는 카드를 오름차순으로 정렬
	sort(mine.begin(), mine.end());

	//이진탐색 시작
	for (int i = 0; i < card.size(); i++)
	{
		int left = 0;
		int right = mine.size() - 1;
		int cnt = 0; //해당 카드를 갖고 있는지 갖고 있지 않은지 판단하기 위한 카운터
		//이진탐색
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (card[i] < mine[mid]) //카드가 비교하려는 카드보다 작으면
			{
				right = mid - 1; //right 조정
			}
			else if (card[i] > mine[mid]) //카드가 비교하려는 카드보다 크면
			{
				left = mid + 1; //left 조정
			}
			else if (card[i] == mine[mid]) //비교하려는 카드와 같으면
			{
				ans.push_back(1); //정답에 1을 푸쉬
				cnt = 1; //카운터를 1로 바꿔줌
				break;
			}
		}
		if (cnt == 0) //서로 일치하는 카드를 찾지 못했으면
			ans.push_back(0); // 정답에 0을 푸쉬
	}

	//정답 출력
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";


}