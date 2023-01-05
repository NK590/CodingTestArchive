#include <iostream>

using namespace std;

int N;
int dp[1001][10];

void Solution()
{
	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				// dp[i][j] += dp[i - 1][k]
				dp[i][j] += dp[i - 1][k] % 10007;
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < 10; i++)
	{
		ret += dp[N][i];
	}

	cout << ret % 10007 << endl;
}

void Input()
{
	cin >> N;
}

int main()
{
	Input();
	Solution();

	return 0;
}