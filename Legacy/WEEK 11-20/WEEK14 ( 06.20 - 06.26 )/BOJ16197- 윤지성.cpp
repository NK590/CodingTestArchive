#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, result = 500;
vector<pair<int, int> >k;
vector<vector<char> >v(21);

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int cnt, int x1, int y1, int x2, int y2) {
	if (cnt == 10)
		return;

	for (int i = 0; i < 4; i++) {
		int n1x = x1 + dx[i];
		int n1y = y1 + dy[i];
		int n2x = x2 + dx[i];
		int n2y = y2 + dy[i];
		
		if (n1x >= 0 && n1x < n && n2x >= 0 && n2x < n && n1y >= 0 && n1y < m && n2y >= 0 && n2y < m) { //범위 내
			if (v[n1x][n1y] == '#' && v[n2x][n2y] == '#')
				continue;
			if (v[n1x][n1y] == '#')
				n1x = x1, n1y = y1;
			if (v[n2x][n2y] == '#')
				n2x = x1, n2y = y1;
			dfs(cnt + 1, n1x, n1y, n2x, n2y);
		}
		else if ((n1x < 0 || n1x >= n || n1y < 0 || n1y >= m) && (n2x < 0 || n2x >= n || n2y < 0 || n2y >= m)) { //범위 외
			continue;
		}
		else {
			if (result > cnt + 1)
				result = cnt + 1;
			return;
		}
	}
}

int main() {
	cin >> n >> m;
	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			v[i].push_back(c); //문자 map 저장
			if (c == 'o') //동전위치 저장
				k.push_back({ i,j });
		}
	}
	dfs(0, k[0].first, k[0].second, k[1].first, k[1].second);
	if (result == 500)
		cout << -1 << endl;
	else
		cout << result << endl;

	return 0;
}
