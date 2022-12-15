#include <iostream>

using namespace std;

// 가로, 세로의 길이는 최대치가 500
constexpr auto MAX = 500;

// 0 빈공간, 1 블록
int map[MAX][MAX];

// 가로 / 세로
int H, W, tempOne;

// 첫 블록을 마킹하는 bool 값
bool leftRight;

// 빗물의 개수
int rainwaterCnt;

bool debugbool = false;

// 시각적인 디버깅을 위한 함수
void VisualDebug()
{
	cout << "\n";
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

// 문제의 입력을 받는 함수
void ReceiveInput()
{
	cin >> H >> W;

	for (int i = 0; i < W; i++)
	{
		cin >> tempOne;
		for (int j = 0; j < tempOne; j++)
		{
			map[i][j] = 1;
		}
	}
}

// 초기화를 진행하는 함수
void Initialization()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			map[i][j] = 0;
		}
	}
}

// 빗물을 카운트 합니다.
void CountRainwater()
{
	rainwaterCnt = 0;

	// 아래부터 위로 검색
	for (int i = 0; i < H; i++)
	{
		leftRight = false;
		tempOne = 0;

		for (int j = 0; j < W; j++)
		{
			if (map[j][i] == 1)
			{
				if (!leftRight)
				{
					// 좌에서 우로 검색하다 처음 블록을 찾으면 마킹
					leftRight = true;
					tempOne = 0;
				}
				else
				{
					// 마킹이 되어있는 상태에서 블록을 찾으면 
					// 빈공간을 카운트하는 tempOne을 결과값에 더해준다.
					// 그리고 0으로 초기화
					rainwaterCnt += tempOne;
					tempOne = 0;
				}

			}
			else if (map[j][i] == 0)
			{
				// 해당 위치가 빈공간이고 첫 블록 마킹이 되어있다면 
				// 빈공간을 카운트하는 tempOne을 하나 늘려줍니다.
				if (leftRight)
				{
					tempOne++;
				}

			}
		}
	}
}

int main()
{
	Initialization();
	ReceiveInput();
	CountRainwater();
	if (debugbool) { VisualDebug(); }
	// 결과를 출력합니다.
	cout << rainwaterCnt;
	return 0;
}