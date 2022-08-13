#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	bool isReverse, isError;

	cin >> t;

	while (t--)
	{
		isError = false;
		isReverse = false;

		deque<int> dq;
		string command, numStr;
		int numCount;
		cin >> command >> numCount >> numStr;

		int numStrLength = numStr.length();
		string num ="";

		// 데크에 문자열정수를 정수로 바꿔 데이터를 입력하는 for문
		for (int numStrIndex = 1; numStrIndex < numStrLength; numStrIndex++)
		{
			// 아무 숫자도 없을 경우 바로 종료 ex [] 입력시
			if (numStr[1] == ']')
			{
				break;
			}

			if (numStr[numStrIndex] >= '0' && numStr[numStrIndex] <= '9')
			{
				num = num + numStr[numStrIndex];
			}
			else if (numStr[numStrIndex] == ',' || numStr[numStrIndex] == ']')
			{
				dq.push_back(stoi(num));
				num.clear();
			}

		}
		// 데크에 저장된 데이터를 요구하는 조건에 따라 R일경우 반전, D일경우 삭제하는 for문
		int commandLength = command.length();
		for (int commandIndex = 0; commandIndex < commandLength; commandIndex++)
		{
			// R일 경우 isReverse 변수만 반전 시켜줌으로써 나중에 데이터를 읽어올때 앞에서부터 읽을건지 뒤에서부터 읽을건지를 정해줌
			if (command[commandIndex] == 'R')
			{
				isReverse = !isReverse;
			}
			// D일경우 데이터를 삭제해줘야함
			else if (command[commandIndex] == 'D')
			{
				if (!dq.empty())
				{
					// 현재 반전중이냐 아니냐에 따라서 데크에 앞에있는 데이터를 삭제할 것인지 뒤에있는 데이터를 삭제할것인지 판단
					if (isReverse)
					{
						dq.pop_back();
					}
					else
					{
						dq.pop_front();
					}
				}
				// 데이터가 없는데 삭제를 요구한다면 Error
				else
				{
					isError = true;
					cout << "error\n";
					break;
				}
			}
		}
		if (!isError)
		{
			cout << "[";
			while (!dq.empty())
			{
				if (isReverse)
				{
					cout << dq.back();
					dq.pop_back();
				}
				else
				{
					cout << dq.front();
					dq.pop_front();
				}
				if (!dq.empty())
				{
					cout << ",";
				}
			}
			cout << "]\n";
		}
	}
	return 0;
}


/*
AC 다국어
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	71764	15948	11146	19.984%
문제
선영이는 주말에 할 일이 없어서 새로운 언어 AC를 만들었다. AC는 정수 배열에 연산을 하기 위해 만든 언어이다. 이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.

함수 R은 배열에 있는 수의 순서를 뒤집는 함수이고, D는 첫 번째 수를 버리는 함수이다. 배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.

함수는 조합해서 한 번에 사용할 수 있다. 예를 들어, "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다. 예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 수를 버리는 함수이다.

배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. T는 최대 100이다.

각 테스트 케이스의 첫째 줄에는 수행할 함수 p가 주어진다. p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.

다음 줄에는 배열에 들어있는 수의 개수 n이 주어진다. (0 ≤ n ≤ 100,000)

다음 줄에는 [x1,...,xn]과 같은 형태로 배열에 들어있는 정수가 주어진다. (1 ≤ xi ≤ 100)

전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.

출력
각 테스트 케이스에 대해서, 입력으로 주어진 정수 배열에 함수를 수행한 결과를 출력한다. 만약, 에러가 발생한 경우에는 error를 출력한다.

예제 입력 1
4
RDD
4
[1,2,3,4]
DD
1
[42]
RRD
6
[1,1,2,3,5,8]
D
0
[]
예제 출력 1
[2,1]
error
[1,2,3,5,8]
error
*/