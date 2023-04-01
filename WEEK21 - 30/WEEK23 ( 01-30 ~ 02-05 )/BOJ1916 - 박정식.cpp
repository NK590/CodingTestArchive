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
		
		//�ִ� �Ÿ��� �ƴ� ��� ��ŵ
		if (distances[current] < distance) continue;
		for (int i = 0; i < graph[current].size(); i++)
		{
			// ���õ� ����� ���� ���
			int next = graph[current][i].first;
			// ���õ� ��带 ���� ���� ���ļ� ���� ���
			int nextDistance = distance + graph[current][i].second;
			// ������ �ּ� ��뺸�� �� �����ϴٸ� ��ü.
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