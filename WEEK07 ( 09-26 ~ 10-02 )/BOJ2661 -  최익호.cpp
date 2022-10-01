#include <iostream>
#include <string>

using namespace std;

int N;
string number;

void DFS(char ch, int cnt)
{
	// 제일 먼저 조건에 부합하는 숫자가 답
	if (cnt - 1 == N) { 
		cout << number; 
		exit(0);
	}
	
	number += ch;
	
	for (int i = 1; i <= cnt/2; i++)
	{
		string a = number.substr(cnt - i, i);
		string b = number.substr(cnt - i * 2, i);

		if (a == b){ 
			// 나쁜 수열이면 지우고 리턴
			number.erase(cnt - 1);
			return;
		}
	}

	for (int i = 1; i <= 3; i++)
	{
		DFS(i + '0', cnt + 1);
	}

	// cnt - 1 자리가 성립하지 않을 경우
	number.erase(cnt - 1);
}

int main()
{
	cin >> N;
	for (int i = 1; i <= 3; i++)
	{
		// '0' 에서 i 만큼 더하면 i
		DFS(i + '0', 1);
	}

	return 0;
}