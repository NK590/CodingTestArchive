#include <iostream>
#include <algorithm>
#pragma warning(disable: 4996)

using namespace std;

int dp[1001][1001];

int main()
{
	int n, m;
	int result = 0;
	scanf("%d", &n);
	scanf("%d", &m);

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			scanf("%1d", &dp[y][x]);
			// 점화식 dp[y][x]가  가질수 있는 최대 정사각형 크기를 구하는 식은 
			// 해당 좌표에 (x-1) 좌표, (x-1, y-1) 좌표, (y-1)좌표를 보고 가장 작은 수 에 1을 더하는 식으로 구할수있습니다.
			// dp[y][x] 값이 0 인경우는 애당초 정사각형을 만들수 없으므로
			// 0이상일 경우에만 점화식 적용
			if (dp[y][x] > 0)
			{
				// 가장 작은 값을 구하는 과정
				int minValue = min(dp[y][x - 1], dp[y - 1][x - 1]);
				minValue = min(minValue, dp[y - 1][x]);

				// 점화식 적용
				dp[y][x] = minValue + 1;
				result = max(result, dp[y][x]);
			}

		}
	}
	cout << result * result;

	return 0;
}