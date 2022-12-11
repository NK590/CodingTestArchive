#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define min(a, b) (a < b ? a : b)
using namespace std;

int n, m, result = 100;
int map[9][9];
int dx[4] = { -1, 1, 0, 0 }; // 상 하 좌 우
int dy[4] = { 0, 0, -1, 1 };
vector<pair<int, int>> v; // cctv 위치 저장

int blindSpotCnt;

void BlindSpot()
{
    blindSpotCnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
                blindSpotCnt++;
        }
    }
}

void SearchMap(queue<pair<int, int>> q, int val) 
{
    while (!q.empty()) 
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        map[x][y] = val;
    }
}

void Dfs(int idx) 
{
    if (idx == v.size()) 
    {
        BlindSpot();
        if (result > blindSpotCnt)
            result = blindSpotCnt;
        return;
    }
    int x = v[idx].first;
    int y = v[idx].second;
    queue<pair<int, int>> q[4];

    for (int i = 0; i < 4; i++) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        while (0 <= nx && nx < n && 0 <= ny && ny < m && map[nx][ny] != 6) 
        {
            if (map[nx][ny] == 0)
                q[i].push({ nx, ny });
            nx += dx[i];
            ny += dy[i];
        }
    } // 4방향으로 볼 수 있는 모든 좌표 q에 저장

    if (map[x][y] == 1) 
    {
        for (int i = 0; i < 4; i++) 
        {
            SearchMap(q[i], -1);
            Dfs(idx + 1);
            SearchMap(q[i], 0);
        }
    }
    // 수평, 수직 2방향
    else if (map[x][y] == 2) 
    {
        for (int i = 0; i < 3; i += 2) 
        {
            SearchMap(q[i], -1);
            SearchMap(q[i + 1], -1);
            Dfs(idx + 1);
            SearchMap(q[i], 0);
            SearchMap(q[i + 1], 0);
        }
    }
    // 4가지
    else if (map[x][y] == 3) 
    { 
        for (int i = 0; i < 2; i++) 
        {
            SearchMap(q[i], -1);
            for (int j = 2; j < 4; j++) 
            {
                SearchMap(q[j], -1);
                Dfs(idx + 1);
                SearchMap(q[j], 0);
            }
            SearchMap(q[i], 0);
        }
    }
    // 3방향
    else if (map[x][y] == 4) 
    { 
        for (int i = 0; i < 4; i++) 
        {
            SearchMap(q[i], -1);
            SearchMap(q[(i + 1) % 4], -1);
            SearchMap(q[(i + 2) % 4], -1);
            Dfs(idx + 1);
            SearchMap(q[i], 0);
            SearchMap(q[(i + 1) % 4], 0);
            SearchMap(q[(i + 2) % 4], 0);
        }
    }
    else 
    {
        for (int i = 0; i < 4; i++)
            SearchMap(q[i], -1);
        Dfs(idx + 1);
        for (int i = 0; i < 4; i++)
            SearchMap(q[i], 0);
    }
}


int main() 
{
    int cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (1 <= map[i][j] && map[i][j] <= 5)
                v.push_back({ i, j });
        }
    }
    Dfs(0);

    cout << result;
}