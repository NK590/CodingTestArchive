#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 100000000

// 테스트케이스수, 노드의 수, 도로의 수, 월홈의 수
int TC, N, M, W;
// 출발노드부터 각 노드의 가기위한 비용값 배열
int dist[501];

vector<pair<int, int>> graph[501];

// 사이클이 있다면 true반환
bool BellmanFord()
{
	// 모든 노드 INF 초기화
	for (int i = 1; i <= N; i++)
		dist[i] = INF;

	// 시작점 0으로 초기화
	dist[1] = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			// j노드를 기준으로 연결된 노드들 체크
			for (int k = 0; k < graph[j].size(); k++)
			{
				int next = graph[j][k].second;
				int cost = graph[j][k].first;

				if (dist[next] > dist[j] + cost)
				{
					dist[next] = dist[j] + cost;
					// N-1까지 확인한 이후에도 갱신이 된다면 음의 사이클이 존재
					if (i == N) return true;
				}

			}
		}
	}
	return false;
}

void Solution()
{
	for (int tc = 0; tc < TC; tc++)
	{
		cin >> N >> M >> W;

		int from;
		int to;
		int distance;

		for (int i = 1; i <= M; i++)
		{
			cin >> from >> to >> distance;

			graph[from].push_back(make_pair(distance, to));
			graph[to].push_back(make_pair(distance, from));
		}

		for (int i = 1; i <= W; i++)
		{
			cin >> from >> to >> distance;

			graph[from].push_back(make_pair(-distance, to));
		}

		if (BellmanFord() == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		for (int i = 1; i <= N; i++)
		{
			graph[i].clear();
		}
	}

}

void Input()
{
	cin >> TC;
}

int main()
{
	Input();
	Solution();

	return 0;
}