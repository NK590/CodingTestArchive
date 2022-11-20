#include<iostream>
#include<queue>

using namespace std;

int N, M;
char map[50][50];
bool visited[50][50][1 << 6];

pair<int, int> start;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int BFS(int a, int b)
{
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    Q.push(make_pair(make_pair(a, b), make_pair(0, 0)));
    visited[a][b][0] = true;

    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Cnt = Q.front().second.first;
        int keys = Q.front().second.second;
        Q.pop();

        if (map[x][y] == '1')
        {
            return Cnt;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (visited[nx][ny][keys] == false)
                {
                    if (map[nx][ny] == '.' || map[nx][ny] == '1')
                    {
                        visited[nx][ny][keys] = true;
                        Q.push(make_pair(make_pair(nx, ny), make_pair(Cnt + 1, keys)));
                    }
                    else if ('a' <= map[nx][ny] && map[nx][ny] <= 'f')
                    {
                        int Tmp_Key = keys | (1 << (int(map[nx][ny] - 'a')));
                        visited[nx][ny][Tmp_Key] = true;
                        Q.push(make_pair(make_pair(nx, ny), make_pair(Cnt + 1, Tmp_Key)));
                    }
                    else if ('A' <= map[nx][ny] && map[nx][ny] <= 'F')
                    {
                        if ((keys & (1 << (int(map[nx][ny]) - 'A'))) != 0)
                        {
                            visited[nx][ny][keys] = true;
                            Q.push(make_pair(make_pair(nx, ny), make_pair(Cnt + 1, keys)));
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string Inp; cin >> Inp;
        for (int j = 0; j < M; j++)
        {
            map[i][j] = Inp[j];
            if (map[i][j] == '0')
            {
                start.first = i;
                start.second = j;
                map[i][j] = '.';
            }
        }
    }

    int result = BFS(start.first, start.second);
    cout << result << "\n";

    return 0;
}