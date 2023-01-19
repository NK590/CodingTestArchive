#include <iostream>
#include <algorithm>
#define INF 999999999

using namespace std;

int n, k;
int coins[10002];
int dp[100002];
void Solution()
{
	for (int i = 1; i < k + 1; i++)
		dp[i] = INF;
	for (int i = 1; i < n + 1; i++)
		dp[coins[i]] = 1;


	for (int i = 1; i < n + 1; i++)
	{
		for (int j = coins[i]; j < k + 1; j++)
		{
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	}

	if (dp[k] == INF)
		cout << -1;
	else
		cout << dp[k];
}

void Input()
{
	cin >> n >> k;
	for (int i = 1; i < n+1; i++)
	{
		cin >> coins[i];
	}
}

int main()
{
	Input();
	Solution();
	return 0;
}