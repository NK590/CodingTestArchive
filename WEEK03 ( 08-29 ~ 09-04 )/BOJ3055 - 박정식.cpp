#define _CRT_SECURE_NO_WARNINGS
#define MAX 50 + 1
#define X second
#define Y first
#include <iostream>
#include <queue>

using namespace std;

// �����¿�
int dx[4] = { 0, 0,-1, 1 };
int dy[4] = { 1, -1, 0, 0 };

char map[MAX][MAX];
int R, C;


queue < pair<int, int>> sq;
queue < pair<int, int>> wq;

void MoveWater()
{
	int cnt = wq.size();
	for (int i = 0; i < cnt; i++)
	{
		pair<int, int> cur = wq.front();
		wq.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C)
				continue;
			if (map[ny][nx] != '.')
				continue;

			map[ny][nx] = '*';
			wq.push({ny, nx});
		}
	}
}

int MoveS()
{
	int time = 0;
	bool check = false;
	while (!sq.empty())
	{
		time++;
		MoveWater();

		int cnt = sq.size();
		for (int i = 0; i < cnt; i++)
		{
			pair<int, int> cur = sq.front();
			sq.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (ny < 0 || nx < 0 || ny >= R || nx >= C)
					continue;
				if (map[ny][nx] == 'D')
				{
					check = true;
					break;
				}
				if (map[ny][nx] != '.')
					continue;

				map[ny][nx] = 'S';
				sq.push({ny, nx});
			}

		}
		if (check == true)
			break;

	}
	if (check == false)
		time = -1;
	return time;
}

void Print()
{
	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
			cout << map[y][x];

		cout << endl;
	}
}

int main()
{
	cin >> R >> C;

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			cin >> map[y][x];

			if (map[y][x] == 'S')
				sq.push({ y, x });
			else if (map[y][x] == '*')
				wq.push({y, x});
		}
	}	
	// * : ��, S ����ġ ��ġ, ����� �� D, �� X

	
	//Print();
	int time = MoveS();
	if (time == -1)
		cout << "KAKTUS" << endl;
	else
		cout << time << endl;

	return 0;
}