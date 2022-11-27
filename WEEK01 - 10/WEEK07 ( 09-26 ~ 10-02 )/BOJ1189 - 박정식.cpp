#define MAX 6
#include <iostream>
#include <stack>

using namespace std;

// 상하좌우 방향 백터
int dx[4] = { 0, 0,-1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int R, C, K, result;
char map[MAX][MAX];
int visit[MAX][MAX];

typedef struct ComBackHome
{
	int y;
	int x;
	int distance;

}Cbh;

void Dfs(Cbh cbh)
{
	if (cbh.distance == K && cbh.x == C - 1 && cbh.y == 0)
	{
		result++;
		return;
	}

	for (int dir = 0; dir < 4; dir++)
	{
		int nx = cbh.x + dx[dir];
		int ny = cbh.y + dy[dir];

		if (ny<0 || nx <0 || ny >= R || nx >= C || visit[ny][nx] == 1)
			continue;
		if (map[nx][ny] == 'T')
			continue;

		// 방문을 한 다음 dfs를 또 호출해 다음 길로 가며 
		// 호출 후에는 해당 길 방문했던 기록을 없앰으로써 다른 경로에서 온 경우를 체크 해야 합니다.
		visit[ny][nx] = 1;
		Dfs({ ny,nx, cbh.distance + 1});
		visit[ny][nx] = 0;

	}
}

void Input()
{
	cin >> R >> C >> K;

	for (int y = 0; y < R; y++)
	{ 
		for (int x = 0; x < C; x++)
		{
			cin >> map[y][x];
		}
	}
}

void Solution()
{
	visit[R - 1][0] = 1;
	Dfs({R-1, 0 , 1});
	cout << result << endl;
}

int main()
{
	Input();
	Solution();
	return 0;
}

