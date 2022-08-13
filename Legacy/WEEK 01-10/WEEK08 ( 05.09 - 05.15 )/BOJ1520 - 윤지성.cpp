#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int m, n;
vector<vector<int> > v(501);
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int dp[501][501];

int dfs(int x, int y) {
	if (dp[x][y] != -1) 
		return dp[x][y];
	
	if (x == m - 1 && y == n - 1)
		return 1;

	dp[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx >= 0 && yy >= 0 && xx < m && yy < n) {
			if (v[xx][yy] < v[x][y]) 
				dp[x][y] += dfs(xx, yy);			
		}
	}

	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> m >> n;

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			v[i].push_back(tmp);
		}
	}	
	cout << dfs(0, 0);

	return 0;
}
