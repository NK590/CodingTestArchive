#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int m, n;
vector<vector<int> > toma(1001);
int visit[1001][1001];
queue<pair<int, int> > q;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0,-1, 1 };
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;

			if (!visit[nx][ny] && !toma[nx][ny]) {
				toma[nx][ny] = toma[x][y] + 1;
				visit[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tmp, max = 0;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			toma[i].push_back(tmp);

			if (tmp == 1) {
				q.push({ i, j });
				visit[i][j] = 1;
			}
		}
	}
	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!toma[i][j]) {
				cout << -1;
				return 0;
			}
			if (toma[i][j] > max)
				max = toma[i][j];
		}
	}

	cout << max - 1;

	return 0;
}



