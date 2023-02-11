#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 10000000

int TC, N, M, W;
int dist[501];
bool cycle;//���� ����Ŭ�� ������ Ȯ��
vector<pair<int, int>> graph[501];

void BellmanFord() 
{
	cycle = false;
	// ��� ��� INF �ʱ�ȭ
	for (int i = 1; i <= N; i++)
		dist[i] = INF; 

	// ������ 0���� �ʱ�ȭ
	dist[1] = 0; 

	for (int i = 1; i <= N; i++) 
	{
		for (int j = 1; j <= N; j++) 
		{
			// j��带 �������� ����� ���� üũ
			for (int k = 0; k < graph[j].size(); k++)
			{
				int next = graph[j][k].second;
				int cost = graph[j][k].first;

				if (dist[next] > dist[j] + cost) 
				{
					dist[next] = dist[j] + cost;
					// N-1���� Ȯ���� ���Ŀ��� ������ �ȴٸ� ���� ����Ŭ�� ����
					if (i == N) cycle = true;
				}

			}
		}
	}
}

void Solution()
{
	for (int tc = 0; tc < TC; tc++)
	{
		cin >> N >> M >> W;

		for (int i = 0; i < M; i++)
		{
			int from;
			int to;
			int distance;
			cin >> from >> to >> distance;
			graph[from].push_back(make_pair(distance, to));
			graph[to].push_back(make_pair(distance, from));
		}

		for (int i = 0; i < W; i++)
		{
			int from;
			int to;
			int distance;
			cin >> from >> to >> distance;
			graph[from].push_back(make_pair(-distance, to));
		}
		BellmanFord();
		if (cycle == true)
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