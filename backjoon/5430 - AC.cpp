#include <iostream>
#include <deque>
#include <string>
#include <algorithm> // reverse 사용 위함
using namespace std;

int main()
{
	int t; //테스트케이스 수
	cin >> t;
	while (t--)
	{
		deque<char> cmd; //명령어를 넣을 덱
		deque<int> arr; //정수 배열 덱
		string p; //명령어
		cin >> p;

		for (int i = 0; i < p.size(); i++)
			cmd.push_back(p[i]); //명령어 삽입

		int n; //배열에 들어있는 개수
		cin >> n;

		string array; //string으로 구성된 배열 [x1, x2, ...]
		string tmpt = ""; //임시 string: string으로 들어온 것을 int형으로 바꿔주기 위함
		cin >> array;
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] >= 48 && array[i] <= 57) //숫자일때
				tmpt += array[i];
			else if (array[i] == ',' || array[i] == ']')
			{
				if (tmpt != "") //임시 string이 공백이 아니면
				{
					int temp = stoi(tmpt); //int형으로 변환
					arr.push_back(temp); //배열에 삽입
					tmpt = ""; //임시 string 초기화
				}
				else
					break;
			}
		}

		/*
			입력받은 배열 사이즈와 덱의 크기가 맞지 않거나
			입력받은 배열의 크기가 0일 때
		*/
		if (n != arr.size() || arr.empty()) 
		{
			cout << "error" << endl; //에러 호출
			break;
		}
		else
		{
			while (!cmd.empty()) //명령어 덱이 빌 때까지 반복
			{
				if (arr.empty() && !cmd.empty()) //명령어 배열은 비어있지 않은데 배열은 비어있으면
				{
					cout << "error" << endl; //에러 출력
					break;
				}
				else if (cmd.front() == 'R') //명령어가 R이면 배열의 순서 뒤집기
				{
					reverse(arr.begin(), arr.end()); //reverse 사용
					cmd.pop_front(); //명령어를 수행했으므로 수행한 명령어 배출
				}
				else if (cmd.front() == 'D') //명령어가 D면 front를 pop
				{
					arr.pop_front();
					cmd.pop_front();
				}
			}

			for (int i = 0; i < arr.size(); i++) //출력
			{
				if (i == 0)
					cout << "[" << arr.at(i) << ",";
				else if (arr.size() - 1 == i)
					cout << arr.at(i) << "]" << endl;
				else
					cout << arr.at(i) << ",";
			}
		}
	}
}