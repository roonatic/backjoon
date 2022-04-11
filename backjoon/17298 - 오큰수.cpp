#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int m;

	int* arr = new int[n]; //입력배열 동적할당
	stack<int> NGE; //계산을 위한 스택
	for (int i = 0; i < n; i++) //먼저 배열에 입력값 추가
	{
		cin >> m;
		arr[i] = m;
	}

	int* ans = new int[n]; //정답 배열 동적할당
	for (int i = n - 1; i >= 0; i--) //입력배열의 맨 뒤에서부터 시작
	{
		while (!NGE.empty() && NGE.top() <= arr[i]) // 계산 스택이 비어있지 않고 top이 기준값보다 작으면
			NGE.pop(); //top을 빼줌 
	
		if (NGE.empty()) //시작값이 맨 오른쪽에 있으면 더 이상 오른쪽은 없기 때문에
			ans[i] = -1; //해당값의 정답은 -1이 된다
		else
			ans[i] = NGE.top(); // top이 기준값보다 크면 정답은 top 

		NGE.push(arr[i]); //기준값을 넣어줘서 앞에서 계산하기 위한 것을 저장
	}

	for (int i = 0; i < n; i++) //정답 출력
			cout << ans[i] << ' ';

}