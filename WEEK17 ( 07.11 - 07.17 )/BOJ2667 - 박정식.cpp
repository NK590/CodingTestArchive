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

// �ϼ�����
int dx[] = { 0, 1, 0, -1};
int dy[] = { 1, 0, -1, 0};

int N;

void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= N || ny < 0 || nx >= N || nx < 0)
            continue;

        if (visit[ny][nx] == 0 && map[ny][nx] == 1)
        {
            visit[ny][nx] = 1;
            cnt++;
            dfs(ny, nx);
        }
    }
}

int main()
{
    int res = 0;
    scanf("%d", &N);

    // ���� ������ �Է�
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
                cnt = 1;                        //ó���� ������ �����ϹǷ� 1�� �ʱ�ȭ
                dfs(y, x);
                cntVec.push_back(cnt);
                res++;                          //���� �׷� 1�� Ž�� ����
            }
        }
    }

    sort(cntVec.begin(), cntVec.end());
    cout << res << "\n";
    for (int i = 0; i < cntVec.size(); i++) 
    {
        cout << cntVec[i] << "\n";
    }


	return 0;
}