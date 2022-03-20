#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main()
{
	int n;
	cin >> n;
	cin.ignore(); //입력 버퍼에 개행문자가 남아있기 떄문에 버퍼 클리어 해줌

	while(n--)
	{
		string input;
		getline(cin, input);
		stack <char> reverse;

		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == ' ') //공백을 맞이하면
			{
				while (!reverse.empty()) //스택 비움
				{
					cout << reverse.top(); //먼저 맨 위의 단어를 출력하고
					reverse.pop(); //단어 제거
				}
				cout << ' '; //이후 공백 출력
			}
			else if (i == input.size() - 1) //문장의 끝 단어면
			{
				reverse.push(input[i]); //해당 단어를 먼저 스택에 추가한 후
				while (!reverse.empty()) //스택이 비워질때까지 맨 위의 단어들을 입력 = 단어들이 뒤집어짐
				{
					cout << reverse.top(); 
					reverse.pop();
				}
				break;
			}
			else
			{
				reverse.push(input[i]);
			}
		}

		cout << endl;
	}
}