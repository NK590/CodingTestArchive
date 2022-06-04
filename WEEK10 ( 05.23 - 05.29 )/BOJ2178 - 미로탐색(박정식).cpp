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
    // ť(Queue) ������ ���� queue ���̺귯�� ��� 
    queue<pair<int, int> > q;
    q.push({ x, y });
    // ť�� �� ������ �ݺ��ϱ� 
    while (!q.empty()) 
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // ���� ��ġ���� 4���� ���������� ��ġ Ȯ��
        for (int i = 0; i < 4; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // �̷� ã�� ������ ��� ��� ����
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // ���� ��� ����
            if (maze[nx][ny] == 0) continue;
            // �ش� ��带 ó�� �湮�ϴ� ��쿡�� �ִ� �Ÿ� ���
            if (maze[nx][ny] == 1) {
                maze[nx][ny] = maze[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }
    // ���� ������ �Ʒ������� �ִ� �Ÿ� ��ȯ
    return maze[n - 1][m - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N, M�� �Է� �ޱ�
    scanf("%d", &n);
    scanf("%d", &m);
    // 2���� ����Ʈ�� �� ���� �Է� �ޱ�
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            scanf("%1d", &maze[x][y]);
        }
    }

    // BFS�� ������ ��� ���
    cout << BFS(0, 0) << '\n';
    return 0; 
}