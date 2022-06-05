#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 행별로 퀸을 놓는 백트래킹 함수
void backtrack(vector<vector<bool>>& board, int& count, int row) {
    // 마지막 행까지 퀸을 무사히 놓았을 시 경우의 수 카운트 하나 추가 후 return
    if (row == board.size()) {
        count++;
        return;
    }
    // 해당 행의 열별로 탐색
    for (int col = 0; col < board.size(); ++col) {
        bool isPossiblePos = true;
        for (int i = row - 1, j = 1; i >= 0; --i, ++j) {
            // 같은 열, 같은 좌측 대각선, 같은 우측 대각선상에 퀸이 있는지 없는지 확인
            bool isInSameCol = board[i][col];
            bool isInLeftDiag = col - j >= 0 && board[i][col - j];
            bool isInRightDiag = col + j <= board.size() - 1 && board[i][col + j];
            // 위 세 경우 중 하나라도 해당 시 퀸을 놓을 수 없음
            if (isInSameCol || isInLeftDiag || isInRightDiag) {
                isPossiblePos = false;
                break;
            }
        }
        // 위 세 경우에 해당하지 않을 시 퀸을 놓을 수 있음 -> 다음 행으로 재귀탐색
        if (isPossiblePos) {
            board[row][col] = true;
            backtrack(board, count, row + 1);
            board[row][col] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int count = 0;
    int row = 0;

    cin >> n;
    vector<vector<bool>> board(n, vector<bool>(n, false));

    backtrack(board, count, row);

    cout << count;
}