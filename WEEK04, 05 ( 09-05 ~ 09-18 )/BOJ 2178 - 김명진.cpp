#include <iostream>
#include <queue>

using namespace std;

int N, M;
queue<pair<int, int>> q;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool map[100][100];
int dis[100][100];

void BFS()
{
	int x, y;
	dis[0][0] = 1;
	q.push(make_pair(0, 0));
	while (q.size() != 0)
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && 0 <= ny && nx < N && ny < M && dis[nx][ny] == 0 && map[nx][ny] == true)
			{
				q.push(make_pair(nx, ny));
				dis[nx][ny] = dis[x][y] + 1;
			}
		}
	}
	cout << dis[N - 1][M - 1];
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			if (str[j] == '1')
			{
				map[i][j] = 1;
			}
			else
			{
				map[i][j] = 0;
			}
			dis[i][j] = 0;
		}
	}
	BFS();
}