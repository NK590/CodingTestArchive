#include<iostream>
#include<vector>

using namespace std;

int N, K, S;
int dp[401][401];
vector<pair<int, int>> v;

void Input()
{
    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int start, end;
        cin >> start >> end;
        dp[start][end] = -1;
        dp[end][start] = 1;
    }
    cin >> S;
    for (int i = 0; i < S; i++)
    {
        int start, end;
        cin >> start >> end;
        v.push_back(make_pair(start, end));
    }
}

void Solution()
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (dp[i][j] == 0)
                {
                    if (dp[i][k] == 1 && dp[k][j] == 1)
                        dp[i][j] = 1;
                    else if (dp[i][k] == -1 && dp[k][j] == -1)
                        dp[i][j] = -1;
                }
            }
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        int start = v[i].first;
        int end = v[i].second;

        cout << dp[start][end] << "\n";
    }
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();

    return 0;
}