#include <iostream>
#include <queue>

using namespace std;

constexpr auto MAX = 100;

// 범위 0 - 99
// 0은 빈공간
// 2 뱀
// 1 사과
int map[MAX][MAX];
int mapN;
int timeCnt;

// 뱀의 위치를 저장
queue<pair<int, int>> snakeQueue;

// 뱀의 이동 시간 및 행동를 저장
// X는 10, 000 이하의 양의 정수
char snakeMoveArr[10000];
// 뱀의 머리위치
pair<int, int> snakeHead;
// 뱀의 머리 방향
int snakeDir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

pair<int, int> tempPair;

bool debug = false;

// 시각적 디버그 확인용
void DebugPrint()
{
	for (int i = 0; i < mapN; i++)
	{
		for (int j = 0; j < mapN; j++)
		{
			cout << map[i][j] << " ";
		}

		cout << "\n";
	}
}

// 맵을 초기화 합니다.
void Initialization()
{
	cin >> mapN;
	timeCnt = 0;

	// 뱀의 행동을 전진으로 초기화
	for (int i = 0; i < 10000; i++)
	{
		snakeMoveArr[i] = 'F';
	}

	// 뱀의 머리의 위치를 초기화
	snakeHead.first = 0;
	snakeHead.second = 0;

	// 맵을 초기화
	for (int i = 0; i < mapN; i++)
	{
		for (int j = 0; j < mapN; j++)
		{
			map[i][j] = 0;
		}
	}
}

// 맵에 사과를 배치합니다.
void GetInput()
{
	int appleCnt = 0;
	cin >> appleCnt;

	while (appleCnt > 0)
	{
		cin >> tempPair.first >> tempPair.second;
		map[tempPair.first -1 ][tempPair.second -1] =  1;
		appleCnt--;
	}

	int snakeMoveCnt = 0;
	cin >> snakeMoveCnt;
	int tempInt;
	char tempChar;

	while (snakeMoveCnt > 0)
	{
		cin >> tempInt >> tempChar;
		snakeMoveArr[tempInt] = tempChar;
		snakeMoveCnt--;
	}
}

// 게임을 시작합니다.
void StartGame(int x, int y)
{
	tempPair.first = x;
	tempPair.second = y;
	snakeQueue.push(tempPair);
	map[x][y] = 2;
	int dir = 0;
	bool snakeDie = false;

	// 뱀이 죽지 않았을 경우 계속 반복
	for (int i = 0; !snakeDie && i < 10000; i++)
	{
		timeCnt++;

		switch (snakeMoveArr[i])
		{
			case 'F':
				snakeHead.first += snakeDir[dir][0];
				snakeHead.second += snakeDir[dir][1];
				break;

			case 'D':
				dir++;
				if (dir >= 4){ dir = 0; }
				snakeHead.first += snakeDir[dir][0];
				snakeHead.second += snakeDir[dir][1];
				break;

			case 'L':
				dir--;
				if (dir <= -1) { dir = 3; }
				snakeHead.first += snakeDir[dir][0];
				snakeHead.second += snakeDir[dir][1];
				break;

			default:
				cout << "i  : " << i << " snakeMoveArr[i] :" << snakeMoveArr[i] << "이거 뜨면 망함";
				break;
		}
		
		// 만약 뱀의 머리가 범위를 벗어나거나 자신의 몸에 부딪혔을 때 
		// 또는 10000번을 넘긴 경우
		if (snakeHead.first <= -1 || snakeHead.first >= mapN || 
			snakeHead.second <= -1 || snakeHead.second >= mapN || 
			map[snakeHead.first][snakeHead.second] == 2 )
		{
			snakeDie = true;
			continue;
		}

		// 만약 뱀의 머리가 사과의 위치일 경우
		if (map[snakeHead.first][snakeHead.second] == 1)
		{   
			// 맵에서 해당 위치를 뱀으로 마킹하고 큐에 넣음 
			map[snakeHead.first][snakeHead.second] = 2;
			snakeQueue.push(make_pair(snakeHead.first, snakeHead.second));
		}
		else // 아닐경우 빈공간
		{
			// 맵에서 해당 위치를 뱀으로 마킹하고 큐에 넣음 
			map[snakeHead.first][snakeHead.second] = 2;
			snakeQueue.push(make_pair(snakeHead.first, snakeHead.second));
			// 꼬리를 하나 없앤다.(이동)
			tempPair.first = snakeQueue.front().first;
			tempPair.second = snakeQueue.front().second;
			map[tempPair.first][tempPair.second] = 0;
			snakeQueue.pop();
		}
	}
}

int main()
{
	Initialization();
	GetInput();
	StartGame(0, 0);

	//시각적 확인용
	if (debug) { DebugPrint(); }

	cout << timeCnt;

	return 0;
}