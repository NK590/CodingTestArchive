#include <iostream>

using namespace std;

constexpr int MAX = 1001;
constexpr int MOD = 10007;

// arr[i][j] 
// i 총 숫자의 개수
// j 선택 개수
// i 개중 j개를 뽑았을때 조합 경우 수
int DP[MAX][MAX];

// DP 배열을 초기화 해주는 함수
void DP_Initialiaztion()
{
    for (int i = 1; i < MAX; i++) {
        DP[i][1] = i; // i개 중 1개를 뽑는 경우의 수는 i개
        DP[i][0] = 1; // i개 중 1개도 선택하지 않는 경우의 수는 1개
        DP[i][i] = 1; // i개 중 i개를 선택하는 경우의 수는 1개
    }
}

int main()
{
    int N, K;
    cin >> N >> K;

    // 배열 초기화
    DP_Initialiaztion();

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            DP[i][j] = (DP[i - 1][j] + DP[i - 1][j - 1]) % MOD;
        }
    }

    cout << DP[N][K]; // 결과 출력하기

    return 0;
}