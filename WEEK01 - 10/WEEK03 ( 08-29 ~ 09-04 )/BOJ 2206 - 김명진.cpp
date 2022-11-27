#include <queue>
#include<cstdio>
#pragma warning(disable:4996)

using namespace std;

int map[1000][1000];
int d[1000][1000][2];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    //시작 칸을 큐에 넣어준다.
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(0, 0), 0));

    //시작칸도 포함이므로 1부터 시작
    d[0][0][0] = 1;


    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            //범위 체크
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            //벽인 경우
            //z == 0 이고 (벽을 부수지 않았고), 벽을 부순상태인 다음 칸에 아직 방문하지 않은 경우
            if (map[nx][ny] == 1 && z == 0 && d[nx][ny][1] == 0) {
                q.push(make_pair(make_pair(nx, ny), 1));
                d[nx][ny][1] = d[x][y][z] + 1;
            }
            else if (map[nx][ny] == 0 && d[nx][ny][z] == 0) {

                //길인 경우 이동할 칸에 방문하지 않았으면 방문
                q.push(make_pair(make_pair(nx, ny), z));
                d[nx][ny][z] = d[x][y][z] + 1;
            }

        }

    }

    //마지막칸의 최솟값을 찾아준다.
    int min = d[n - 1][m - 1][0];
    if (min != 0) {
        if (d[n - 1][m - 1][1] != 0 && min > d[n - 1][m - 1][1]) {
            min = d[n - 1][m - 1][1];
        }
    }
    else {
        if (d[n - 1][m - 1][1] != 0) {
            min = d[n - 1][m - 1][1];
        }
    }

    //도착하지 못한 경우 -1을 출력
    if (min == 0) {
        printf("%d", -1);
    }
    else {
        printf("%d", min);
    }

    return 0;
}