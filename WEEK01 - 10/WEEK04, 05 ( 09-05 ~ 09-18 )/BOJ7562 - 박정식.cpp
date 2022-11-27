#define MAX 300 + 1
#define Y first
#define X second
#include <iostream>
#include <queue>

using namespace std;


// 나이트의 탐색 방향 일반적인 상하좌우가 아니에요.
// https://www.acmicpc.net/problem/7562
// 총 8방향이동 하니까 배열도 8개 만들어주기
// 좌상단부터 우상단순으로 넣었어요
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int map[MAX][MAX];
// I : 체스판의 크기는 I*I 이에요
int I;
queue<pair<int, int>> q;

void reset()
{
	for (int y = 0; y < I; y++)
	{
		for (int x = 0; x < I; x++)
		{
			map[y][x] = 0;
		}
	}

	while (!q.empty())
		q.pop();
}

void Bfs(int y, int x)
{
	if (map[y][x] == -1)
	{
		map[y][x] = 0;
		return;
	}
	

	q.push({y, x});
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		

		for (int dir = 0; dir < 8; dir++)
		{
			int ny = cur.Y + dy[dir];
			int nx = cur.X + dx[dir];

			// 탐색 지점이 맵을 벗어났다면 스킵
			if (ny < 0 || nx < 0 || ny >= I || nx >= I)
				continue;
			// 도착 지점을 찾았다면 지금 맵에 걸린 시간에서 1을 더하고 함수를 바로 끝낸다.
			if (map[ny][nx] == -1)
			{
				map[ny][nx] = map[cur.Y][cur.X];
				return;
			}
			// 이미 방문한 지점이라면 스킵한다
			if (map[ny][nx] != 0)
				continue;

			map[ny][nx] = map[cur.Y][cur.X] + 1;
			q.push({ny, nx});
				
		}
	}
}

int main()
{
	// t : 테스트케이스 개수
	int t;
	cin >> t;

	// 테스트케이스 개수만큼 실행
	for (int i = 0; i < t; i++)
	{
		cin >> I;

		// 나이트 시작 지점
		int startY, startX;
		cin >> startY >> startX;
		// 나이트 도착 지점
		int endY, endX;
		cin >> endY >> endX;

		// 시작 지점은 1부터 시작
		map[startY][startX] = 1;
		map[endY][endX] = -1;

		Bfs(startY, startX);
		cout << map[endY][endX] << "\n";
		reset();
	}

	return 0;
}