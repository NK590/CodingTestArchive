#include <iostream>
#include <queue>
#include <stdio.h>
#pragma warning(disable: 4996)

int maze[201][201];

int dx[] = { -1 ,1 , 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m;

using namespace std;

int BFS(int x, int y) 
{
    // 큐(Queue) 구현을 위해 queue 라이브러리 사용 
    queue<pair<int, int> > q;
    q.push({ x, y });
    // 큐가 빌 때까지 반복하기 
    while (!q.empty()) 
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // 현재 위치에서 4가지 방향으로의 위치 확인
        for (int i = 0; i < 4; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 미로 찾기 공간을 벗어난 경우 무시
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 벽인 경우 무시
            if (maze[nx][ny] == 0) continue;
            // 해당 노드를 처음 방문하는 경우에만 최단 거리 기록
            if (maze[nx][ny] == 1) {
                maze[nx][ny] = maze[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }
    // 가장 오른쪽 아래까지의 최단 거리 반환
    return maze[n - 1][m - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N, M을 입력 받기
    scanf("%d", &n);
    scanf("%d", &m);
    // 2차원 리스트의 맵 정보 입력 받기
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            scanf("%1d", &maze[x][y]);
        }
    }

    // BFS를 수행한 결과 출력
    cout << BFS(0, 0) << '\n';
    return 0; 
}