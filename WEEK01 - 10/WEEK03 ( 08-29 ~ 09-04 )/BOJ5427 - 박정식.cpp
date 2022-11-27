#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000 + 1
#define X second
#define Y first
#include <iostream>
#include <queue>

using namespace std;

// »óÇÏÁÂ¿ì
int dx[4] = { 0, 0,-1, 1 };
int dy[4] = { 1, -1, 0, 0 };

char map[MAX][MAX];
int w, h;

queue < pair<int, int>> sq;
queue < pair<int, int>> fq;

void MoveFire()
{
	int cnt = fq.size();
	for (int i = 0; i < cnt; i++)
	{
		pair<int, int> cur = fq.front();
		fq.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w)
				continue;
			if (map[ny][nx] != '.')
				continue;

			map[ny][nx] = '*';
			fq.push({ ny, nx });
		}
	}
}

int MoveS()
{
	int time = 0;
	while (!sq.empty())
	{
		time++;
		MoveFire();

		int cnt = sq.size();
		for (int i = 0; i < cnt; i++)
		{
			pair<int, int> cur = sq.front();
			sq.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (ny < 0 || nx < 0 || ny >= h || nx >= w)
					return time;

				if (map[ny][nx] != '.')
					continue;

				map[ny][nx] = '@';
				sq.push({ ny, nx });
			}
		}
	}

	return -1;
}

void Reset(int w, int h)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			map[y][x] = '.';
		}
	}
	while (!sq.empty())
		sq.pop();
	while (!fq.empty())
		fq.pop();
}

int main()
{
	int t;
	cin >> t;	

	for (int i = 0; i < t; i++)
	{
		cin >> w >> h;
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				cin >> map[y][x];

				if (map[y][x] == '@')
					sq.push({ y, x });
				else if (map[y][x] == '*')
					fq.push({ y, x });
			}
		}
		int time = MoveS();
		if (time == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << time << endl;

		Reset(w, h);
	}

	return 0;
}