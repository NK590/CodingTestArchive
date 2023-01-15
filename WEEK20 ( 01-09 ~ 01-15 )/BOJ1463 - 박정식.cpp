#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];
int N;
void Solution()
{
    for (int i = 2; i <= N; i++)
    {
        // DP[i] = x 의 의미는 "i를 1로 만드는데 취해야 하는 연산의 최소 횟수는 x번 입니다." 이다.

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
