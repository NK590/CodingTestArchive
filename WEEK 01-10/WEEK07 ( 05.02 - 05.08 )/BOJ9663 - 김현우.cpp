#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// �ະ�� ���� ���� ��Ʈ��ŷ �Լ�
void backtrack(vector<vector<bool>>& board, int& count, int row) {
    // ������ ����� ���� ������ ������ �� ����� �� ī��Ʈ �ϳ� �߰� �� return
    if (row == board.size()) {
        count++;
        return;
    }
    // �ش� ���� ������ Ž��
    for (int col = 0; col < board.size(); ++col) {
        bool isPossiblePos = true;
        for (int i = row - 1, j = 1; i >= 0; --i, ++j) {
            // ���� ��, ���� ���� �밢��, ���� ���� �밢���� ���� �ִ��� ������ Ȯ��
            bool isInSameCol = board[i][col];
            bool isInLeftDiag = col - j >= 0 && board[i][col - j];
            bool isInRightDiag = col + j <= board.size() - 1 && board[i][col + j];
            // �� �� ��� �� �ϳ��� �ش� �� ���� ���� �� ����
            if (isInSameCol || isInLeftDiag || isInRightDiag) {
                isPossiblePos = false;
                break;
            }
        }
        // �� �� ��쿡 �ش����� ���� �� ���� ���� �� ���� -> ���� ������ ���Ž��
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