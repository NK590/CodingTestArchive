#define _CRT_SECURE_NO_WARNINGS
#define X first
#define Y second
#define MAX 1000+1

#include <iostream>
#include <queue>

using namespace std;

int visited[MAX][MAX];
int map[MAX][MAX];

// 동서남북
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

// M : 가로길이, N : 세로 길이
int N, M;
int result;
queue<pair<int, int>> q;

// 맵에 안익은 토마토가 있는지 체크
void check()
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {           
            if (map[x][y] == 0)
            {
                // 마지막에 --를 해주므로 0으로 초기화해서 안익은 토마토가 있을경우 -1값 유도
                result = 0;
                return;
            }
        }
    }
}

void bfs()
{    
    while (!q.empty())
    {
        // q에 들어있는 토마토를 꺼내서 cur에 할당
        pair<int, int> cur = q.front();
        q.pop();

        // 각 맵에는 익는데 까지 걸린 소요일-1 값을 갖고있으므로 q에서 꺼낸 토마토의 값을 비교하여 최대값 구하기  
        if (result < map[cur.X][cur.Y])
            result = map[cur.X][cur.Y];

        for (int dir = 0; dir < 4; dir++)
        {                  
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // 동서남북 탐색중 배추밭을 벗어나거나 
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            // 이미 방문을 했던곳이거나, 해당지역에 안익은 토마토가 없을경우 방문할 필요가 없으므로 방문처리 X
            if (visited[nx][ny] == 1 || map[nx][ny] != 0)
                continue;
            visited[nx][ny] = 1;
            // 방문할때마다 익게만든 토마토가 갖고있는값에서 1씩 더해줌
            map[nx][ny] = map[cur.X][cur.Y] + 1;

            // 방문한지역에도 익은 토마토가 새롭게 생겼으므로 q에 넣어주기
            q.push({ nx, ny });
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    scanf("%d %d", &M, &N);
    // M : 가로길이, N : 세로 길이
    // 맵 정보 입력
    for (int x = 0; x < N; x++) 
    {
        for (int y = 0; y < M; y++) 
        {
            scanf("%d", &map[x][y]);
            // 맵 정보 입력중 토마토가 있을경우 q에 미리 넣어둔다.
            if (map[x][y] == 1)
            {
                q.push({ x, y });
                // q에 있는 지역은 반드시 방문을 할예정이므로 미리 방문체크
                visited[x][y] = 1;
            }
        }
    }

    bfs();
    check();

    result--;
    printf("%d", result);


    return 0;
}