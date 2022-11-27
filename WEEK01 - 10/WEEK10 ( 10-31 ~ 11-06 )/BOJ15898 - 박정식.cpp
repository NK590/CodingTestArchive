#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <map>
#include <iostream>

using namespace std;
int n;
int ingres[10][4][4][4][2];
int used[10];
int picks[3];
int rotates[3];
int place[4][2] = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } };
int placed[3];
int sumArr[5];
int kiln[5][5][2];
map<char, int> convert;

// 3. 재료를 배치하는 모든 경우의 수를 만듭니다.
int makeBomb(int depth) {
	if (depth == 3) {
		// 4. 폭탄을 만듭니다.
		for (int i = 0; i < 3; i++) {
			int y = place[placed[i]][0];
			int x = place[placed[i]][1];
			int pick = picks[i];
			int rotate = rotates[i];

			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					kiln[j + y][k + x][0] = max(0, min(9, kiln[j + y][k + x][0] + ingres[pick][rotate][j][k][0]));

					if (ingres[pick][rotate][j][k][1] > 0) {
						kiln[j + y][k + x][1] = ingres[pick][rotate][j][k][1];
					}
				}
			}
		}

		for (int i = 0; i < 5; i++) sumArr[i] = 0;

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				sumArr[kiln[i][j][1]] += kiln[i][j][0];
				kiln[i][j][0] = kiln[i][j][1] = 0;
			}
		}

		return sumArr[1] * 7 + sumArr[2] * 5 + sumArr[3] * 3 + sumArr[4] * 2;
	}

	int ret = 0;

	for (int i = 0; i < 4; i++) {
		placed[depth] = i;
		ret = max(ret, makeBomb(depth + 1));
	}

	return ret;
}

// 2. 재료를 돌리는 모든 경우의 수를 만듭니다.
int go(int depth) {
	if (depth == 3) return makeBomb(0);

	int ret = 0;

	for (int i = 0; i < 4; i++) {
		rotates[depth] = i;
		ret = max(ret, go(depth + 1));
	}

	return ret;
}

// 1. 재료를 뽑는 모든 순열을 만듭니다.
int slove(int depth) {
	if (depth == 3) return go(0);

	int ret = 0;

	for (int i = 0; i < n; i++) {
		if (used[i]) continue;

		picks[depth] = i;
		used[i] = 1;
		ret = max(ret, slove(depth + 1));
		used[i] = 0;
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	convert['W'] = 0;
	convert['R'] = 1;
	convert['B'] = 2;
	convert['G'] = 3;
	convert['Y'] = 4;

	cin >> n;

	for (int i = 0; i < n; i++) {
		// 효능 저장
		for (int k = 0; k < 4; k++) {
			for (int l = 0; l < 4; l++) {
				cin >> ingres[i][0][k][l][0];
			}
		}

		// 색깔을 정수로 변환해서 저장
		for (int k = 0; k < 4; k++) {
			for (int l = 0; l < 4; l++) {
				char c;

				cin >> c;

				ingres[i][0][k][l][1] = convert[c];
			}
		}

		// 재료를 90, 180, 270도 회전한 모드를 저장해놓기
		for (int j = 1; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					ingres[i][j][k][l][0] = ingres[i][j - 1][4 - l - 1][k][0];
					ingres[i][j][k][l][1] = ingres[i][j - 1][4 - l - 1][k][1];
				}
			}
		}
	}

	cout << slove(0);

	return 0;
}