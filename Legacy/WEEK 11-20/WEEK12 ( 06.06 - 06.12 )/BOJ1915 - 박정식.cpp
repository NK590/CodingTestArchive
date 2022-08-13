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
			// ��ȭ�� dp[y][x]��  ������ �ִ� �ִ� ���簢�� ũ�⸦ ���ϴ� ���� 
			// �ش� ��ǥ�� (x-1) ��ǥ, (x-1, y-1) ��ǥ, (y-1)��ǥ�� ���� ���� ���� �� �� 1�� ���ϴ� ������ ���Ҽ��ֽ��ϴ�.
			// dp[y][x] ���� 0 �ΰ��� �ִ��� ���簢���� ����� �����Ƿ�
			// 0�̻��� ��쿡�� ��ȭ�� ����
			if (dp[y][x] > 0)
			{
				// ���� ���� ���� ���ϴ� ����
				int minValue = min(dp[y][x - 1], dp[y - 1][x - 1]);
				minValue = min(minValue, dp[y - 1][x]);

				// ��ȭ�� ����
				dp[y][x] = minValue + 1;
				result = max(result, dp[y][x]);
			}

		}
	}
	cout << result * result;

	return 0;
}