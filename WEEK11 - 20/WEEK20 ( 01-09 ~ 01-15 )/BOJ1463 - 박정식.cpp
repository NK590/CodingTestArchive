#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];
int N;
void Solution()
{
    for (int i = 2; i <= N; i++)
    {
        // DP[i] = x �� �ǹ̴� "i�� 1�� ����µ� ���ؾ� �ϴ� ������ �ּ� Ƚ���� x�� �Դϴ�." �̴�.

        dp[i] = 99999999;
        dp[i] = min(dp[i], dp[i - 1] + 1);
        if (i % 2 == 0) 
            dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0) 
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    cout << dp[N] << endl;
}

void Input()
{
    cin >> N;
}
int main() 
{
    Input();
    Solution();
}
