#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 99999

int supply[101];
vector<pair<int, int>> node[101];
int dp[101][101];


void dijkstra(int first)
{
	dp[first][first] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,first });

	while (!pq.empty()) {
		int now_node = pq.top().second;
		int now_len = -pq.top().first;
		pq.pop();

		if (dp[first][now_node] < now_len) continue;

		for (pair<int, int> next : node[now_node]) {
			int next_node = next.second;
			int next_len = next.first + now_len;

			if (next_len < dp[first][next_node]) {
				dp[first][next_node] = next_len;
				pq.push({ -next_len,next_node });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, r;

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
	{
		int supplyAmount;
		cin >> supplyAmount;
		supply[i] = supplyAmount;
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = MAX;
		}
	}

	for (int i = 1; i <= r; i++) {
		int localA, localB, length; cin >> localA >> localB >> length;
		node[localA].push_back({ length,localB });
		node[localB].push_back({ length,localA });
	}
	
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
	}

	int result = 0;

	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] <= m) temp += supply[j];
		}
		result = max(temp, result);
	}

	cout << result;

	return 0;
}
