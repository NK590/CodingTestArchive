#include <iostream>
#include <vector>

using namespace std;

int arr[101];
int dp[101][21];

int main() 
{
    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    dp[1][arr[1]]++;
    for (int i = 2; i < N; i++) 
    {
        for (int j = 0; j <= 20; j++) 
        {
            if (dp[i - 1][j]) 
            {
                if (j + arr[i] <= 20)
                {
                    dp[i][j + arr[i]] += dp[i - 1][j];
                }
                if (j - arr[i] >= 0)
                {
                      dp[i][j - arr[i]] += dp[i - 1][j];
                }
                
            }
        }
    }

    cout << dp[N - 1][arr[N]] << endl;
    return 0;
}