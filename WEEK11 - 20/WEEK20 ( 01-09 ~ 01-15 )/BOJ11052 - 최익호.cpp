#include <iostream>

using namespace std;

// 구매하려는 카드의 개수
int N, result;

int arr[1001];

// dp[i][j] = 최대값
// i = 목표의 카드수
// j = 카드의 순서
int dp[1001][1001];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}


	for (int j = 1; j <= N; j++) {
		for (int i = 1; i <= N; i++) {
			if (i > j) {
				dp[j][i] = dp[j][i-1];
				result = max(result, dp[j][i]);
			}
			else
			{
				dp[j][i] = max(dp[j][i-1], dp[j - i][i] + arr[i]);
				result = max(result, dp[j][i]);
			}
		}
	}

	cout << result;

	return 0;
}