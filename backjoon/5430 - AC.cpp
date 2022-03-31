#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	int t; //테스트케이스 수
	cin >> t;
	while (t--)
	{
		bool chk = true; //정방향인지 역방향인지 체크위함
		bool err = false; //에러 체크용
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
				if (tmpt == "") //아무것도 안 들어오면 빈 배열
					break;
				else
				{
					int temp = stoi(tmpt);
					arr.push_back(temp);
					tmpt = ""; //초기화
				}
			}
		}

		if (n != arr.size() || (arr.empty() && cmd.front() == 'D'))
			err = true;
		else
		{
			while (!cmd.empty())
			{
				if (cmd.front() == 'R')//R이면 뒤집기 명령 수행
				{
					if (chk == true) //정방향이면
						chk = false; //방향을 역으로 표시
					else //역방향이면
						chk = true; //정방향으로

					cmd.pop_front();
				}
				else if (cmd.front() == 'D') //D면 맨 앞의 원소 삭제
				{
					if (arr.empty())//맨 앞 원소를 삭제해야하는데 앞이 비어있으면
					{
						err = true;
						break;
					}
					else
					{
						if (chk == true) //정방향일 때
						{
							arr.pop_front();
							cmd.pop_front();
						}
						else //역방향일 때
						{
							arr.pop_back();
							cmd.pop_front();
						}
					}
				}
			}
		}

		if (arr.empty() && cmd.empty()) //빈 배열일때
			cout << "[]" << endl;
		else if (err == true) //에러 출력
			cout << "error" << endl;
		else
		{
			if (chk == true) //정방향이면
			{
				cout << "[";
				for (int i = 0; i < arr.size(); i++)
				{
					if (i == arr.size()-1)
						cout << arr.at(i) << "]" << endl;
					else
						cout << arr.at(i) << ",";
				}
			}
			else //역순 출력
			{
				cout << "[";
				for (int i = arr.size()-1; i >= 0; i--)
				{
					if (i == 0)
						cout << arr.at(i) << "]" << endl;
					else
						cout << arr.at(i) << ",";
				}
			}
		}
	}
}