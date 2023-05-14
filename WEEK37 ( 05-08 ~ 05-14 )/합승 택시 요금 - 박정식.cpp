#define INF 10000000

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector <pair<int, int>> graph[201];
int distances[201][201];

void Dijkstra(int startIndex, int n)
{
	for (int i = 1; i <= n; i++)
	{
		distances[startIndex][i] = INF;
	}
	distances[startIndex][startIndex] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, startIndex));

	while (!pq.empty())
	{
		// 3. 방문하지 않는 노드 중 가장 cost가 적은 노드 선택.
		int distance = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		//최단 거리가 아닌 경우 스킵
		if (distances[startIndex][current] < distance) continue;

		// 4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용을 갱신.
		// 현재 연결된 노드중 가장 낮은 cost를 갖는 노드의 연결된 노드들을 확인
		for (int i = 0; i < graph[current].size(); i++)
		{
			// 선택된 노드를 인접 노드로 거쳐서 가는 비용
			int nextDistance = distance + graph[current][i].first;
			// 선택된 노드의 인접 노드
			int next = graph[current][i].second;
			// 기존의 최소 비용보다 더 저렴하다면 교체.
			if (nextDistance < distances[startIndex][next])
			{
				distances[startIndex][next] = nextDistance;
				// 방문할 수 있는 노드이므로 이노드들에서도 탐색 시작
				pq.push(make_pair(-nextDistance, next));
			}

		}
	}
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
	int answer = 0;

	for (int idx = 0; idx < fares.size(); idx++)
	{
		int from = fares[idx][0];
		int to = fares[idx][1];
		int distance = fares[idx][2];

		graph[from].push_back(make_pair(distance, to));
		graph[to].push_back(make_pair(distance, from));
	}

	for (int idx = 1; idx <= n; idx++)
	{
		Dijkstra(idx, n);
	}

	answer = INF;
	for (int idx = 1; idx <= n; idx++)
	{
		if (answer > distances[s][idx] + distances[idx][a] + distances[idx][b])
			answer = distances[s][idx] + distances[idx][a] + distances[idx][b];
	}

	return answer;
}