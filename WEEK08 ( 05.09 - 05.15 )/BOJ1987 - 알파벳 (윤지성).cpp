#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
/*1987*/
int c, r, big;
vector<vector<char> > v(21, vector<char>(21)); //맵 입력받을 변수
vector<vector<int> > visit(21, vector<int>(21)); //방문 기록할 변수
vector<char> alpha; //방문알파벳 기록
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int x, int y) {	
	if (visit[x][y] > big)
		big = visit[x][y]; //최대값 저장 변수
	

	for (int i = 0; i < 4; i++) {
		if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= c || y + dy[i] >= r) //범위 벗어날 경우
			continue;
		alpha.erase(alpha.begin() + visit[x][y] + 1, alpha.end()); //현재 위치 이후 탐색된 알파벳 제거
		
		if (find(alpha.begin(), alpha.end(), v[x + dx[i]][y + dy[i]]) == alpha.end()) {	//방문안한 알파벳일 경우
			visit[x + dx[i]][y + dy[i]] = visit[x][y] + 1; //이전단계 +1로 방문처리
			alpha.push_back(v[x + dx[i]][y + dy[i]]); //알파벳 넣기
			dfs(x + dx[i], y + dy[i]); //다음단계 탐색
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> r;
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			cin >> v[i][j];
		}
	}
	alpha.push_back(v[0][0]);
	dfs(0, 0);
	
	cout << big + 1;

	return 0;
}
