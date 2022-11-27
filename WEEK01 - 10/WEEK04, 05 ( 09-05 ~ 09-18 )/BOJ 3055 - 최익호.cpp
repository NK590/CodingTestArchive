#include <iostream>
#include <queue>

using namespace std;

//맵의 크기는 최대 50
#define MAX 100

char map[MAX][MAX];
int mapCheck[MAX][MAX];

// 행과 열
int row, column = 0;

queue<pair<int, int>> myQ;
queue<pair<int, int>> waterQ;

int D[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
// 좌 우 상 하

// 초기화
void Initialization()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			map[i][j] = 'O';
		}
	}

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			mapCheck[i][j] = -1;
		}
	}

	cin >> column >> row;

	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			char temp;
			cin >> temp;
			map[i][j] = temp;
		}
	}
}

int BFS()
{
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (map[i][j] == '*')
			{
				// 물의 위치를 큐에 저장
				waterQ.push(pair<int, int>(i, j));
			}
		}
	}

	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (map[i][j] == 'S')
			{
				// 고슴도치의 처음 위치를 큐에 저장
				myQ.push(pair<int, int>(i, j));
				mapCheck[i][j] = 0;
			}
		}
	}

	while (!myQ.empty())
	{

		while (!waterQ.empty())
		{
			pair <int, int> w = waterQ.front();
			waterQ.pop();

			for (int i = 0; i < 4; i++)
			{
				// 상하 좌우로 검색
				int nx = w.first + D[i][0];
				int ny = w.second + D[i][1];

				// 맵의 범위를 넘어간 경우, 비버의 굴 또는 바위, 물의 위치일 경우 넘김
				if (nx < 0 || nx > column || ny < 0 || ny > row || map[nx][ny] == 'X' || map[nx][ny] == 'D' || map[nx][ny] == 'O' || map[nx][ny] == '*')
				{
					continue;
				}

				map[nx][ny] = '*';
			}

			mapCheck[w.first][w.second] = -2;
			map[w.first][w.second] = 'X';
		}

		while (!myQ.empty())
		{
			pair <int, int> r = myQ.front();
			myQ.pop();

			for (int i = 0; i < 4; i++)
			{
				// 상하 좌우로 검색
				int nx = r.first + D[i][0];
				int ny = r.second + D[i][1];

				// 맵의 범위를 넘어간 경우, 비버의 굴 또는 바위, 물의 위치일 경우 넘김
				if (nx < 0 || nx > column || ny < 0 || ny > row || map[nx][ny] == 'X' || map[nx][ny] == 'O' || map[nx][ny] == '*')
				{
					continue;
				}

				mapCheck[nx][ny] = mapCheck[r.first][r.second] + 1;
				
				if (map[nx][ny] == 'D')
				{
					return mapCheck[nx][ny];
				}

				map[nx][ny] = 'S';
			}

			mapCheck[r.first][r.second] = -2;
			map[r.first][r.second] = 'X';
		}

		for (int i = 0; i < column; i++)
		{
			for (int j = 0; j < row; j++)
			{
				if (map[i][j] == '*')
				{
					waterQ.push(pair<int, int>(i, j));
				}
			}
		}

		for (int i = 0; i < column; i++)
		{
			for (int j = 0; j < row; j++)
			{
				if (map[i][j] == 'S')
				{
					// 고슴도치의 위치를 큐에 저장
					myQ.push(pair<int, int>(i, j));
				}
			}
		}
	}

	return -1;
}



int main()
{
	// 맵을 초기화
	Initialization();
	int result;
	result = BFS();

	if (result == -1)
	{
		cout << "KAKTUS";
	}
	else
	{
		cout << result;
	}

	return 0;
}
