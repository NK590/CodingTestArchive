#include <string>
#include <vector>

using namespace std;

constexpr int Max = 30;

int N, M;

char map[Max][Max];
bool mapCheck[Max][Max];


void CheckRectangle(int x, int y, char c)
{
	bool check = false;

	if (x + 1 < M && y + 1 < N) { 

		if (map[x][y + 1] == c && map[x + 1][y + 1] == c && map[x + 1][y] == c) {
			check = true;
			mapCheck[x][y + 1] = true;
			mapCheck[x + 1][y + 1] = true;
			mapCheck[x + 1][y] = true;
		}
	}

	if (check) mapCheck[x][y] = true;


}


int solution(int m, int n, vector<string> board) {

	M = m;
	N = n;

    int answer = 0;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].length(); j++) {
			map[i][j] = board[i][j];
		}
	}
	

	while (true) {
		int cnt = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != ' ') CheckRectangle(i, j, map[i][j]);
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (mapCheck[i][j]) { // 블록을 터뜨림
					map[i][j] = ' ';
					mapCheck[i][j] = false;
					cnt++;		
				}
			}
		}

		for (int i = m - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == ' ') {
					for (int k = i; k >= 0; k--) {
						if (map[k][j] != ' ') {
							map[i][j] = map[k][j];
							map[k][j] = ' ';
							break;
						}
					}
				}
			}
		}

		if (cnt == 0) break;
		else answer += cnt;
	}

    return answer;
}