#include <iostream>
#include <queue>

using namespace std;

int N, T, G;
// N: LED의 숫자, T: 버튼을 누를 수 있는 횟수, G: 목표 숫자
int result = 0;
// 결과
bool failConditionCheck = true;
// 조건을 벗어날경우 true;

queue<int> myQ;
//BFS에서 사용한 queue

#define MAX 100000

int check[MAX];

// 버튼 A 기능의 함수
int BtnA(int number)
{
	number += 1;
	return number;
}

// 버튼 B 기능의 함수
int BtnB(int number)
{
	number *= 2;

	int i = 10000;
	while (i >= 1)
	{
		if (number / i != 0)
		{
			number -= i;
			break;
		}
		i = i / 10;
	}

	return number;
}

// 초기화 함수
void Initialization()
{
	cin >> N >> T >> G;
	
	//배열 초기화
	for (int i = 0; i < MAX; i++)
	{
		check[i] = 0;
	}
}

// BFS 기능의 함수
void BFS(int N)
{
	myQ.push(N);
	while (!myQ.empty())
	{
		int a = myQ.front();
		myQ.pop();

		// 방문한 적이 있거나 실행횟수가 T를 넘어가면 스킵
		if (check[a] > T)
		{
			continue;
		}

		if (a == G)
		{
			failConditionCheck = false;
		}

		for (int i = 0; i < 2; i++)
		{
			int temp = 0;
			switch (i)
			{
				case 0:
					if (a >= 99999)
					{
						break;
					}
					temp = BtnA(a);
					if (check[temp] == 0)
					{
						myQ.push(temp);
						check[temp] = check[a] + 1;
					}
					break;

				case 1:
					if (a > 49999)
					{
						break;
					}
					temp = BtnB(a);
					if (check[temp] == 0)
					{
						myQ.push(temp);
						check[temp] = check[a] + 1;
					}
					break;
			}
		}
	}
}

int main()
{
	Initialization();
	BFS(N);

	if (failConditionCheck)
	{
		cout << "ANG";
	}
	else
	{
		result = check[G];
		cout << result;
	}

	return 0;
}