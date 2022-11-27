#include <iostream>
#include <queue>

using namespace std;
#define MAX 1001

int N, M;
int days = -1;
bool flag = false;
int tomato[MAX][MAX];
int visited[MAX][MAX];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
queue<pair<int, int>> q;

int main() {
    cin >> M >> N;

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            cin >> tomato[i][j];
            visited[i][j] = -1;

            if (tomato[i][j] == 1) {
                q.push({ i,j });
                visited[i][j]++;
            }
        }
    }

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i = 0;i < 4;i++) {
            int na = a + dx[i];
            int nb = b + dy[i];
            if (na >= 0 && nb >= 0 && N > na && M > nb && visited[na][nb] == -1 && tomato[na][nb] == 0) {
                q.push({ na,nb });
                visited[na][nb] = visited[a][b] + 1;
            }
        }
    }

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            if (days <= visited[i][j]) {
                days = visited[i][j];
            }
            if (tomato[i][j] == 0 && visited[i][j] == -1) {
                days = -1;
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    cout << days;
}