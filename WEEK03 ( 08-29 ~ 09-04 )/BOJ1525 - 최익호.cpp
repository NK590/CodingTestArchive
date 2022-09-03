#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

string puzzle; // 퍼즐의 상태를 저장할 변수

queue<pair<string, int>> myqueue;
// 퍼즐의 초기상태와 실행 횟수를 넣어줌
// 탐색 시 상 / 하 / 좌 / 우 움직임 정의

set<string> checkset;
// 상태가 중복되는 것을 허용하지 않게 만듬(최단거리를 계산해준다.)
// 같은 값을 넣어도 하나만 존재

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int result = -1;

void BfsAndCheck()
{
	myqueue.push({puzzle, 0});
	checkset.insert(puzzle);
	
	while (!myqueue.empty())
	{

		string currentString = myqueue.front().first;
		int countTry = myqueue.front().second;
		myqueue.pop();



		if (currentString == "123456780" &&(result == -1 || result > countTry))
		{
			result = countTry;
		}

		int zeroPos = currentString.find('0'); //  0의 위치찾고 반복자를 찾음

		// 인덱스 값으로 행과 열의 값을 가져온다.
		int x = zeroPos / 3;
		int y = zeroPos % 3;


		// 해당 위치에서 상 하 좌 우 4가지 방향으로 자리를 바꾸면서 큐에 넣어준다. 
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 범위를 넘어가면 넘김
			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
			{
				continue;
			}

			string next = currentString;
			//   현위치, 다음 위치를 바꿈
			swap(next[x * 3 + y], next[nx * 3 + ny]);

			// 방문한 경험이 있는지 확인
			if (checkset.count(next) == 0)
			{
				checkset.insert(next);
				myqueue.push({ next, countTry + 1 });
			}
		}
	}
}

// 값을 입력받아 퍼즐을 셋팅
void Init()
{
	char temp;
	for (int i = 0; i < 9; i++)
	{
		cin >> temp;
		puzzle.push_back(temp); // 문자열의 맨 끝에 추가
	}
}

int main()
{
	Init();
	BfsAndCheck();
	//cout << ANSWER << "\n" << puzzle;
	cout << result;
	return 0;
}