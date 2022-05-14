#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_LENGTH 21

using namespace std;

int r, c;
char board[MAX_LENGTH][MAX_LENGTH];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
bool alphabetList[26] = { false, }; // �湮�� ���ĺ� üũ�� boolean �迭
int maxPath = 0; // �ִ� ������ ĭ ��

// ��� ��Ʈ��ŷ �Լ��� �ִ� ������ �� �ִ� ĭ �� Ž��
void backtrack(int x, int y, int tempPath) {
    // ��� ȣ��ø��� maxPath ����
    maxPath = max(maxPath, tempPath);

    // �����¿� 4���� Ž��
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < r && 0 <= ny && ny < c) { // ���ǵ� ���� ĭ ���� ����� ���� ��
            if (!alphabetList[((int)board[nx][ny]) - 65]) { // ���� �ش� ���ĺ��� �湮���� �ʾ��� ��
                alphabetList[((int)board[nx][ny]) - 65] = true;
                backtrack(nx, ny, tempPath + 1); // �ش� ���ĺ� �湮 �� �� ���� ĭ���� ��� Ž��
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

    // �ʱ� ��� ��ġ (0, 0)�� ������ Ž���ϹǷ� �ش� ĭ�� ���ĺ��� �湮 üũ
    alphabetList[((int)board[0][0]) - 65] = true;

    // (0, 0)���� �ʱ� �湮ĭ�� 1�� ��Ʈ��ŷ ��� Ž��
    backtrack(0, 0, 1);

    cout << maxPath;
}