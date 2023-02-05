#define INF 1000000000

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int startIndex, endIndex;
vector <pair<int, int>> graph[1001];
int distances[1001];

void Dijkstra(int start)
{
	distances[start] = 0;
	priority_queue<pair<int, int>> pq;

	pq.push(make_pair(start, 0));
	while (!pq.empty())
	{
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();
		
		//최단 거리가 아닌 경우 스킵
		if (distances[current] < distance) continue;
		for (int i = 0; i < graph[current].size(); i++)
		{
			// 선택된 노드의 인접 노드
			int next = graph[current][i].first;
			// 선택된 노드를 인접 노드로 거쳐서 가는 비용
			int nextDistance = distance + graph[current][i].second;
			// 기존의 최소 비용보다 더 저렴하다면 교체.
			if (nextDistance < distances[next])
			{
				distances[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

void Solution()
{
	for (int i = 1; i <= N; i++)
		distances[i] = INF;

	Dijkstra(startIndex);

	cout << distances[endIndex] << endl;	
}


void Input()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int vertex;
		int adjVertex;
		int distance;
		cin >> vertex >> adjVertex >> distance;
		graph[vertex].push_back(make_pair(adjVertex, distance));
	}
	cin >> startIndex >> endIndex;
}

int main()
{
	Input();
	Solution();

	return 0;
}