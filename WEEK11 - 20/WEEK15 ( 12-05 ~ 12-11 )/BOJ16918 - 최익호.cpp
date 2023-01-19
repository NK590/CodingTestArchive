#include <iostream>
#include <list>

using namespace std;

// R, C, N 의 최대값 매크로
constexpr auto MAX = 200;

// 격자판 구현
// 범위 0 ~ 199
char map[MAX][MAX];

// 디버그용
bool debug = true;

int R, C, N;

// 지난 시간을 카운트
int timeCnt;

// 폭발할 폭탄의 위치를 가지는 리스트
list<pair<int, int>> locationBombList;
list<pair<int, int>>::iterator iterListBomb;

// 폭탄의 터지는 방향 정의
int dirExplosion[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };


// 시각적을 확인하기 위함
void DebugPrint()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << map[i][j];
		}

		cout << "\n";
	}
}

// 초기화를 하는 함수
void Initialization()
{
	// 시간 초기화
	timeCnt = 0;

	// 모두 빈칸으로 초기화
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			map[i][j] = '.';
		}
	}
}

// 입력을 받는 함수
void GetInput()
{
	cin >> R >> C >> N;

	// 초기 맵 입력받기
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
		}
	}
}



// 폭발할 폭탄의 리스트를 작성합니다.
void CreateBombList()
{
	// 리스트를 초기화
	locationBombList.clear();

	// 정해진 범위 내에서 폭탄을 찾아서 리스트에 추가합니다.
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 'O')
			{
				locationBombList.push_back(make_pair(i, j));
			}
		}
	}
}

// 빈공간이면 폭탄으로 바꾸어 줍니다.
void BlankSpaceBombFilling()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == '.')
			{
				map[i][j] = 'O';
			}
		}
	}
}

// 리스트의 폭탄을 폭발시킵니다.
void bombExplosion()
{
	pair<int, int> tempPair;

	for (iterListBomb = locationBombList.begin(); iterListBomb != locationBombList.end(); iterListBomb++)
	{
		tempPair.first = iterListBomb->first;
		tempPair.second = iterListBomb->second;

		//자신의 위치를 빈공간으로 만들어 줍니다.
		map[tempPair.first][tempPair.second] = '.';

		// 폭탄의 상 하 좌 우를 빈공간으로 만들어 줍니다.
		for (int i = 0; i < 4; i++)
		{
			// 허용된 범위를 벗어나면 넘긴다.
			if (tempPair.first + dirExplosion[i][0] <= -1 || tempPair.first + dirExplosion[i][0] >= R 
				|| tempPair.second + dirExplosion[i][1] <= -1 || tempPair.second + dirExplosion[i][1] >= C)
			{
				continue;
			}

			// 상하좌우를 빈공간으로 만들어줍니다. (폭발 효과)
			switch (i)
			{
				case 0:
					map[tempPair.first + dirExplosion[i][0]][tempPair.second + dirExplosion[i][1]] = '.';
					break;

				case 1:

					map[tempPair.first + dirExplosion[i][0]][tempPair.second + dirExplosion[i][1]] = '.';
					break;

				case 2:
					map[tempPair.first + dirExplosion[i][0]][tempPair.second + dirExplosion[i][1]] = '.';
					break;

				case 3:
					map[tempPair.first + dirExplosion[i][0]][tempPair.second + dirExplosion[i][1]] = '.';
					break;
			}

		}
	}
}

// 게임을 시작
void StartGame()
{
	CreateBombList();
	timeCnt++;
	if (timeCnt == N) { return; }

	BlankSpaceBombFilling();
	timeCnt++;
	if (timeCnt == N) { return; }

	// 원하는 시간이 될때까지 진행
	while (true)
	{
		bombExplosion();
		CreateBombList();
		timeCnt++;
		if (timeCnt == N) { break; }

		BlankSpaceBombFilling();
		timeCnt++;
		if (timeCnt == N) { break; }
	}
}

int main()
{
	Initialization();
	GetInput();
	StartGame();

	if (debug) { DebugPrint(); }

	return 0;
}
