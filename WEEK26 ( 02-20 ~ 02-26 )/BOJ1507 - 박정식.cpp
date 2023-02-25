#include<iostream>
#include<vector>

#define INF 100000000

using namespace std;

int distances[21][21];
int map[21][21];
int N;


void Input()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int cost;
            cin >> cost;
            distances[i][j] = cost;
            map[i][j] = cost;
        }
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
                if (i == k || j == k)
                    continue;

                if (distances[i][j] == distances[i][k] + distances[k][j])
                    map[i][j] = 0;
                else if (distances[i][j] > distances[i][k] + distances[k][j])
                {
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            result += map[i][j];
        }
    }
    cout << result/2 << endl;
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