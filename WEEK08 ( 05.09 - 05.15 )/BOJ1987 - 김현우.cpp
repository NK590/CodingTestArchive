#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_LENGTH 21

using namespace std;

int r, c;
char board[MAX_LENGTH][MAX_LENGTH];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
bool alphabetList[26] = { false, }; // 방문한 알파벳 체크용 boolean 배열
int maxPath = 0; // 최대 지나간 칸 수

// 재귀 백트래킹 함수로 최대 지나갈 수 있는 칸 수 탐색
void backtrack(int x, int y, int tempPath) {
    // 재귀 호출시마다 maxPath 갱신
    maxPath = max(maxPath, tempPath);

    // 상하좌우 4방향 탐색
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < r && 0 <= ny && ny < c) { // 정의된 보드 칸 수를 벗어나지 않을 때
            if (!alphabetList[((int)board[nx][ny]) - 65]) { // 아직 해당 알파벳을 방문하지 않았을 때
                alphabetList[((int)board[nx][ny]) - 65] = true;
                backtrack(nx, ny, tempPath + 1); // 해당 알파벳 방문 후 그 다음 칸으로 재귀 탐색
                alphabetList[((int)board[nx][ny]) - 65] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }

    // 초기 출발 위치 (0, 0)은 무조건 탐색하므로 해당 칸의 알파벳은 방문 체크
    alphabetList[((int)board[0][0]) - 65] = true;

    // (0, 0)에서 초기 방문칸수 1로 백트래킹 재귀 탐색
    backtrack(0, 0, 1);

    cout << maxPath;
}