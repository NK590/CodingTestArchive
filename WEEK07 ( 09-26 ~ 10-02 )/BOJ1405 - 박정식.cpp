#include <iostream>
#include <cmath>
#include <string.h>
#include <stack>
using namespace std;


typedef long double ld;

struct Probe
{
    int x;
    int y;
    ld p; 
    int cnt;
};

int N, e, w, s, n;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
long double dp[4];
bool visit[30][30];
long double ans = 0;

void Dfs(Probe probe) 
{
    if (visit[probe.x][probe.y]) return;
    if (probe.cnt == N) {
        ans += probe.p;
        return;
    }

    visit[probe.x][probe.y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = probe.x + dx[i];
        int ny = probe.y + dy[i];
        Dfs({ nx, ny, probe.p * dp[i], probe.cnt + 1 });
    }
    visit[probe.x][probe.y] = false;
}


int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> N >> e >> w >> s >> n;
    dp[0] = (ld)s / 100; 
    dp[1] = (ld)n / 100; 
    dp[2] = (ld)w / 100; 
    dp[3] = (ld)e / 100;

    Dfs({ 14, 14, 1, 0 });

    cout << fixed;
    cout.precision(20);
    cout << ans;

    return 0;
}