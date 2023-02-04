#define INF 1000000000

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E;
int startIndex;
vector <pair<int, int>> graph[20001];
int distances[20001];

void Dijkstra(int start)
{
	distances[start] = 0;
	priority_queue<pair<int, int>> pq;

	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		
		//최단 거리가 아닌 경우 스킵
		if (distances[current] < distance) continue;

		for (int i = 0; i < graph[current].size(); i++)
		{
			// 선택된 노드의 인접 노드
			int next = graph[current][i].second;
			// 선택된 노드를 인접 노드로 거쳐서 가는 비용
			int nextDistance = distance + graph[current][i].first;
			// 기존의 최소 비용보다 더 저렴하다면 교체.
			if (nextDistance < distances[next])
			{
				distances[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
}

void Solution()
{
	for (int i = 1; i <= V; i++)
		distances[i] = INF;

	Dijkstra(startIndex);
	
	for (int i = 1; i <= V; i++)
	{
		if (distances[i] != INF)
			cout << distances[i] << "\n";
		else
			cout << "INF" << "\n";
	}
}


void Input()
{
	cin >> V >> E;

	cin >> startIndex;

	for (int i = 0; i < E; ++i)
	{
		int vertex;
		int adjVertex;
		int distance;
		cin >> vertex >> adjVertex >> distance;
		graph[vertex].push_back(make_pair(distance, adjVertex));
	}
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}