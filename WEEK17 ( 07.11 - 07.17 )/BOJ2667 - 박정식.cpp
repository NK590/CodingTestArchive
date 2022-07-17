#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int visit[26][26];
int map[26][26];
vector<int> cntVec;
int cnt;

// 북서남동
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int N;

void dfs(int y, int x)
{

    for (int dir = 0; dir < 4; dir++)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
            continue;

        if (map[ny][nx] == 1 && visit[ny][nx] == 0)
        {
            visit[ny][nx] = 1;
            cnt++;
            dfs(ny, nx);
        }
    }
}

int main()
{
    scanf("%d", &N);

    // 지도 데이터 입력
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            scanf("%1d", &map[y][x]);
        }
    }


    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (map[y][x] == 1 && visit[y][x] == 0)
            {
                visit[y][x] = 1;
                cnt = 1;
                dfs(y, x);
                cntVec.push_back(cnt);
            }
        }
    }

    int cntVecSize = cntVec.size();
    sort(cntVec.begin(), cntVec.end());

    printf("%d\n", cntVecSize);
    for (int index = 0; index < cntVecSize; index++)
    {
        printf("%d\n", cntVec[index]);
    }

    return 0;
}