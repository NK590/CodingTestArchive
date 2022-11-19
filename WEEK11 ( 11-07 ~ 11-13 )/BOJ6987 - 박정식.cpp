#include <iostream>
using namespace std;

int team1[] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
int team2[] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };
int answer[4], match[6][3], result[6][3];

void Dfs(int tc, int round) 
{
    // 15개 경기 종료
    if (round == 15) 
    {
        for (int r = 0; r < 6; r++) 
        {
            for (int c = 0; c < 3; c++) 
            {
                // 예측 한 곳이라도 맞지 않는 경우
                if (match[r][c] != result[r][c])
                    return;
            }
        }

        // 모든 예측이 일치한다면 가능한 결과로 처리
        answer[tc] = 1;
        return;
    }

    // {승리(0), 무승부(1), 패배(2)}
    int t1 = team1[round];
    int t2 = team2[round];

    // t1 승, t2 패
    result[t1][0]++; 
    result[t2][2]++;
    Dfs(tc, round + 1);
    result[t1][0]--; 
    result[t2][2]--;

    // t1 무, t2 무
    result[t1][1]++; 
    result[t2][1]++;
    Dfs(tc, round + 1);
    result[t1][1]--; 
    result[t2][1]--;

    // t1 패, t2 승
    result[t1][2]++; 
    result[t2][0]++;
    Dfs(tc, round + 1);
    result[t1][2]--; 
    result[t2][0]--;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int TC = 0; TC < 4; ++TC) 
    {
        for (int r = 0; r < 6; ++r) 
        {
            for (int c = 0; c < 3; c++) 
            {
                cin >> match[r][c];
            }
        }
        Dfs(TC, 0);
    }

    for (int i = 0; i < 4; i++)
        cout << answer[i] << ' ';
    cout << "\n";
}