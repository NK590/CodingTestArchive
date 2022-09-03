#define _CRT_SECURE_NO_WARNINGS
#define MAX 30 + 1
#define X second
#define Y first
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct pos
{
	int l, y, x;
};

// »óÇÏÁÂ¿ì
int dx[4] = { 0, 0,-1, 1 };
int dy[4] = { 1, -1, 0, 0 };
// À§Ãþ, ¾Æ·¡Ãþ
int dl[2] = {1, -1};

int map[MAX][MAX][MAX];
int L, R, C;


queue <pos> q;


int Bfs()
{
	while (!q.empty())
	{
		pos cur = q.front();
		q.pop();
		//Print();
		// »óÇÏÁÂ¿ì
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C)
				continue;
			if (map[cur.l][ny][nx] == 2)
				return map[cur.l][cur.y][cur.x];
			
			if (map[cur.l][ny][nx] != 0)
				continue;

			map[cur.l][ny][nx] = map[cur.l][cur.y][cur.x] + 1;
			pos npos;	// Next Position
			npos.l = cur.l;
			npos.y = ny;
			npos.x = nx;
			q.push(npos);
		}
		// À§Ãþ ¾Æ·¡Ãþ
		for (int dir = 0; dir < 2; dir++)
		{
			int nl = cur.l + dl[dir];
			if (nl < 0 || nl >= L)
				continue;
			if (map[nl][cur.y][cur.x] == 2)
				return map[cur.l][cur.y][cur.x];
			
			if (map[nl][cur.y][cur.x] != 0)
				continue;

			map[nl][cur.y][cur.x] = map[cur.l][cur.y][cur.x] + 1;
			pos npos;	// Next Position
			npos.l = nl;
			npos.y = cur.y;
			npos.x = cur.x;
			q.push(npos);
		}

	}

	return -1;

	
}

void Print()
{
	for (int l = 0; l < L; l++)
	{
		for (int y = 0; y < R; y++)
		{
			for (int x = 0; x < C; x++)
			{
				cout << map[l][y][x];
			}
			cout << endl;
		}
	}

}

void Reset()
{
	for (int l = 0; l < L; l++)
	{
		for (int y = 0; y < R; y++)
		{
			for (int x = 0; x < C; x++)
			{
				map[l][y][x] = '.';
			}
		}
	}
	while (!q.empty())
		q.pop();

}

int main()
{
	// #º®, . ºóÄ­, S ½ÃÀÛ ÁöÁ¡, E Ãâ±¸
	while(true)
	{
		cin >> L >> R >> C;
		if (L == 0)
			break;


		for (int l = 0; l < L; l++)
		{
			for (int y = 0; y < R; y++)
			{
				for (int x = 0; x < C; x++)
				{
					char ch;
					cin >> ch;

				    if (ch == '.')
					map[l][y][x] = 0;
					else if (ch == '#')
						map[l][y][x] = 1;
					else if (ch == 'E')
						map[l][y][x] = 2;
					else if(ch == 'S')
					{
						map[l][y][x] = 3;
						pos spos;	// start Position
						spos.l = l;
						spos.y = y;
						spos.x = x;
						q.push(spos);
					}				

				}
			}
		}

		int time = Bfs();
		if (time == -1)
			cout << "Trapped!" << endl;
		else
			cout << "Escaped in " <<  time - 2 << " minute(s)." << endl;
		Reset();
		
	}




	return 0;
}