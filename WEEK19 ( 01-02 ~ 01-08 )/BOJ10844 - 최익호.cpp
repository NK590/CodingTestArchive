#include <iostream>

using namespace std;

constexpr int MOD = 1000000000;

int N;

// dp[i][j] 
// i = 숫자, j = 자릿수
long long dp[10][101];

// DP 초기화
void DP_Initialization()
{
	dp[0][1] = 0;
	for (int i = 1; i < 10; i++) {
		dp[i][1] = 1;
	}
}

int main()
{
	cin >> N;

	long long result = 0;

	DP_Initialization();

	for (int j = 2; j <= N; j++) {
		for (int i = 0; i < 10; i++) {
			if (i == 0) { // 마지막 숫자가 0
				dp[i][j] = dp[1][j-1]; 
			}
			else if (i == 9) { // 마지막 숫자가 9
				dp[i][j] = dp[8][j-1];
			}
			else {
				// 모듈러 연산 덧셈
				dp[i][j] = ( (dp[i-1][j-1] % MOD) + ( dp[i + 1][j - 1] % MOD) ) % MOD;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		result += ( dp[i][N] % MOD ); // 모듈러 연산 덧셈
	}

	cout << result % MOD; // 모듈러 연산 덧셈

	return 0;
}