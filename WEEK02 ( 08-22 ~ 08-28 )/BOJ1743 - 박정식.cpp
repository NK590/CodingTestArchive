#include <iostream>
#include <stack>

#define X first
#define Y second
#define MAX 100 + 2

using namespace std;

int map[MAX][MAX];
int visit[MAX][MAX];
//			상 하 좌 우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

// N : 세로 길이, M : 가로 길이, K : 쓰레기의 개수
int N, M, K;
int result;

void Dfs(int x, int y)
{
	int cnt = 1;
	stack<pair<int, int>> s;
	s.push({x, y});
	visit[x][y] = 1;

	while (!s.empty())
	{
		pair<int, int> cur = s.top();
		s.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 1 || ny < 1 || nx > M || ny > N)
				continue;

			if (visit[nx][ny] == 1 || map[nx][ny] == 0)
				continue;

			s.push({nx, ny});
			visit[nx][ny] = 1;
			cnt++;
		}
	}
	if (result < cnt)
		result = cnt;
}

int main()
{
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		map[y][x] = 1;
	}

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= M; x++)
		{
 			if (visit[x][y] == 0 && map[x][y] == 1)
			{
				Dfs(x, y);
			}
		}
	}

	cout << result;
	return 0;
}