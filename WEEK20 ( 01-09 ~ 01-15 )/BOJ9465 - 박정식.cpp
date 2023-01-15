#include <iostream>
#include <algorithm>
#include <memory.h> 

using namespace std;

int dp[100001][2];
int map[100001][2];
int T;
void Solution()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		memset(dp, 0, sizeof(dp));
		memset(map, 0, sizeof(dp));
		int n;
		cin >> n;

		for (int y = 0; y < 2; y++)
		{
			for (int x = 0; x < n; x++)
			{
				cin >> map[x][y];
			}
		}

		dp[0][0] = map[0][0];
		dp[0][1] = map[0][1];
		dp[1][0] = map[0][1] + map[1][0];
		dp[1][1] = map[0][0] + map[1][1];
		for (int i = 2; i < n; i++)
		{
			dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]) + map[i][0];
			dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + map[i][1];
		}
		cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;

	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
	return 0;
}