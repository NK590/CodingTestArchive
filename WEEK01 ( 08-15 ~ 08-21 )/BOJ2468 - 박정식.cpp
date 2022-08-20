#define _CRT_SECURE_NO_WARNINGS
#define X first
#define Y second
#define MAX 101+1

#include <iostream>
#include <queue>

using namespace std;

int visited[MAX][MAX];
int map[MAX][MAX];

// 동서남북
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

// N : 맵 크기
int N;
int safetyArea;
queue<pair<int, int>> q;


void bfs(int height)
{
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        visited[cur.X][cur.Y] = 1;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // 배열 범위 벗어나는지 체크
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;

            if (map[nx][ny] <= height || visited[nx][ny] == 1)
                continue;
            visited[nx][ny] = 1;

            q.push({ nx, ny });
        }
    }
}

void reset()
{
    safetyArea = 0;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            visited[x][y] = 0;
        }
    }
}

int main()
{
    int height = 0, result = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);

    scanf("%d", &N);
    // M : 가로길이, N : 세로 길이
    // 맵 정보 입력
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            scanf("%d", &map[x][y]);
            if (height < map[x][y])
                height = map[x][y];
        }
    }

    while (height >= 0)
    {
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                if (map[x][y] > height && visited[x][y] == 0)
                {
                    q.push({ x, y });
                    bfs(height);
                    safetyArea++;
                }
            }
        }
        if (result < safetyArea)
            result = safetyArea;

        reset();
        height--;
    }


    printf("%d", result);
    return 0;
}