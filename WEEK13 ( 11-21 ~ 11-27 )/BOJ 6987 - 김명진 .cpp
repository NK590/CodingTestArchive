#include <iostream>

using namespace std;

const int homeT[] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
const int awayT[] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };

int answer[4], caseBoard[6][3], result[6][3];

void DFS(int caseNum, int matchNum) {
    if (matchNum == 15) {
        if (answer[caseNum]) return;

        for (int r = 0; r < 6; r++) {
            for (int c = 0; c < 3; c++) {
                if (caseBoard[r][c] != result[r][c])
                    return;
            }
        }

        answer[caseNum] = 1;
        return;
    }

    int t1 = homeT[matchNum];
    int t2 = awayT[matchNum];

    result[t1][0]++; result[t2][2]++;
    DFS(caseNum, matchNum + 1);
    result[t1][0]--; result[t2][2]--;

    result[t1][1]++; result[t2][1]++;
    DFS(caseNum, matchNum + 1);
    result[t1][1]--; result[t2][1]--;

    result[t1][2]++; result[t2][0]++;
    DFS(caseNum, matchNum + 1);
    result[t1][2]--; result[t2][0]--;
}


int main() {

    for (int i = 0; i < 4; ++i) {
        for (int r = 0; r < 6; ++r) {
            for (int c = 0; c < 3; c++) {
                cin >> caseBoard[r][c];
            }
        }
        DFS(i, 0);
    }

    for (int i = 0; i < 4; i++)
        cout << answer[i] << ' ';
    cout << "\n";
}