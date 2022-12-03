#include <iostream>
#include <queue>
#include <vector>
#define Y first
#define X second

using namespace std;

char map[12][6];
int result;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visit[12][6];

bool bfs(int y, int x, char c) 
{ 
    //�μ̴��� �Ⱥμ̴��� return
    queue<pair<int, int>> q;
    vector<pair<int, int>> v; //size�� 4 �̻�Ǹ� ��Ʈ���� �ƴϸ� �ʱ�ȭ�Ѵ�.
    memset(visit, false, sizeof(visit));
    q.push({ y,x });
    v.push_back({ y,x });
    visit[y][x] = 1;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) 
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= 6 || ny >= 12 || visit[ny][nx])
                continue;
            if (map[ny][nx] == c && !visit[ny][nx])
            {
                q.push({ ny,nx });
                v.push_back({ ny,nx });
                visit[ny][nx] = 1;
            }
        }
    }

    if (v.size() >= 4) {
        int vs = v.size();
        for (int i = 0; i < vs; i++) {
            map[v[i].Y][v[i].X] = '.';
        }
        return true;
    }

    return false; //���ν�
}

void gravity() 
{

    for (int i = 0; i < 6; i++) 
    { //�� �̵�
        queue<char> q;
        for (int j = 12 - 1; j >= 0; j--) 
        { //�� �Ʒ��� ���� ť�� �ִ´�
            if (map[j][i] != '.') 
            {
                q.push(map[j][i]);
            }
        }
        int qs = q.size();
        for (int j = 12 - 1; j >= 12 - qs; j--) 
        {
            map[j][i] = q.front(); q.pop();
        }
        for (int j = 12 - qs - 1; j >= 0; j--) 
        {
            map[j][i] = '.';
        }
    }


}


int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //init
    for (int i = 0; i < 12; i++) 
    {
        string s;
        cin >> s;
        for (int j = 0; j < 6; j++) 
        {
            map[i][j] = s[j];
        }
    }

    while (1) 
    {
        int flag = 0;
        for (int i = 0; i < 12; i++) 
        {
            for (int j = 0; j < 6; j++) 
            {
                if (map[i][j] != '.')
                {
                    if (bfs(i, j, map[i][j])) 
                    {
                        flag++;
                    }
                }
            }
        }

        if (flag == 0) 
            break;
        else 
        {
            //�ϳ��� ��Ʈ������ �ٽ� ������ ���� ������ �Լ� ���
            result++;
            gravity();
        }

    }

    if (result)
        cout << result;
    else if 
        (result == 0) cout << 0;

}