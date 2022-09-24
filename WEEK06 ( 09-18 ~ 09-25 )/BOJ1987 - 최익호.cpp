#include <iostream>

using namespace std;

// 행, 열, 결과
int row, column, result;

// 알파벳 중복 방지
bool isVisited[26];

// 맵 표시
char mapArr[20][20];

// 상 하 좌 우
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void DFS(int x, int y, int cnt) {

    // 결과값보다 높으면 값을 바꾸어 준다.
    if (cnt > result)
    {
        result = cnt;
    }

    for (int i = 0;i < 4;i++)
    {
        // 상 하 좌 우 움직여주기
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 범위를 벗어나면 실행 X
        if (nx >= 0 && ny >= 0 && nx < column && ny < row)
        {
            // A - 65  이번 배열에 A가 있다면 -65 = 0
            // isVisited[0] 방문 처리
            if (isVisited[mapArr[ny][nx] - 'A'] == false)
            {
                isVisited[mapArr[ny][nx] - 'A'] = true;
                DFS(nx, ny, cnt + 1);
                isVisited[mapArr[ny][nx] - 'A'] = false;
                // DFS가 끝나면서 방문처리 해제
            }
        }
    }
}

int main() 
{
    cin >> row >> column;

    for (int i = 0;i < row;i++) 
    {
        for (int j = 0;j < column;j++) 
        {
            cin >> mapArr[i][j];
        }
    }

    // 첫시작
    isVisited[mapArr[0][0] - 'A'] = true;

    // DFS 시작
    DFS(0, 0, 1);

    cout << result;

    return 0;
}