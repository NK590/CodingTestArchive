#include<iostream>
#include<vector>

#define INF 100000000

using namespace std;

int distances[251][251];
int n, m, k;
vector<pair<int, int>> v;

void Input()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i == j)
                distances[i][j] = 0;
            else
                distances[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, b;
        cin >> u >> v >> b;

        distances[u][v] = 0;
        distances[v][u] = 0;

        if (b == 0)
            distances[v][u] = 1;
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int start, end;
        cin >> start >> end;
        v.push_back(make_pair(start, end));
    }
}

void Solution()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (distances[i][j] > distances[i][k] + distances[k][j])
                    distances[i][j] = distances[i][k] + distances[k][j];
            }
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        int start = v[i].first;
        int end = v[i].second;

        cout << distances[start][end] << "\n";
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