#define MAX 30 + 1

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct pos
{
	int l, r, c;
};

// »óÇÏÁÂ¿ì À§Ãþ, ¾Æ·¡Ãþ
int dx[6] = { 0, 0,-1, 1 , 0, 0};
int dy[6] = { 1, -1, 0, 0, 0, 0};
int dl[6] = { 0, 0, 0, 0, 1, -1};

int map[MAX][MAX][MAX];
int L, R, C;

queue <pos> q;

int Bfs()
{
	while (!q.empty())
	{
		pos cur = q.front();
		q.pop();

		// »óÇÏÁÂ¿ì À§Ãþ, ¾Æ·¡Ãþ
		for (int dir = 0; dir < 6; dir++)
		{
			int nc = cur.c + dx[dir];
			int nr = cur.r + dy[dir];
			int nl = cur.l + dl[dir];

			if (nr < 0 || nc < 0 ||  nl < 0 || nr >= R || nc >= C  || nl >= L)
				continue;
			if (map[nl][nr][nc] == 2)
				return map[cur.l][cur.r][cur.c];
			
			if (map[nl][nr][nc] != 0)
				continue;

			map[nl][nr][nc] = map[cur.l][cur.r][cur.c] + 1;
			q.push({ nl, nr, nc });
		}

	}
	return -1;	
}

void Reset()
{
	for (int l = 0; l < L; l++)
	{
		for (int r = 0; r < R; r++)
		{
			for (int c = 0; c < C; c++)
			{
				map[l][r][c] = '.';
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
			for (int r = 0; r < R; r++)
			{
				for (int c = 0; c < C; c++)
				{
					char ch;
					cin >> ch;

				    if (ch == '.')
					map[l][r][c] = 0;
					else if (ch == '#')
						map[l][r][c] = 1;
					else if (ch == 'E')
						map[l][r][c] = 2;
					else if(ch == 'S')
					{
						map[l][r][c] = 3;
						q.push({ l, r, c });
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