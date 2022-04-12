#include <iostream>
#include <stack>
using namespace std;

#define MAX 1000001

int main()
{
	int n, m;
	cin >> n;

	int* arr = new int[n]; //입력 배열 동적할당
	int* ans = new int[n]; //정답 배열 동적할당
	int cnt[MAX] = { 0, }; //등장 횟수를 계산하는 배열
	stack<int> NGF; //오등큰수를 계산하기 위한 스택

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		arr[i] = m;
		cnt[m] += 1; //각 숫자가 얼마나 등장했는가
	}

	for (int i = n-1; i >= 0; i--) //입력배열의 맨 뒤에서부터 시작
	{
		int tmpt = arr[i]; 
		while (!NGF.empty() && cnt[NGF.top()] <= cnt[tmpt]) //계산 스택이 비어있지 않고등장 횟수가 top보다 크면
			NGF.pop(); //pop

		if (NGF.empty()) //계산 스택이 비어있으면 맨 오른쪽이라는 뜻이므로
			ans[i] = -1;  //-1 출력
		else
			ans[i] = NGF.top(); //해당 오등큰수 찾음

		NGF.push(tmpt);
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
}