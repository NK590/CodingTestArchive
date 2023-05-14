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
		// 3. �湮���� �ʴ� ��� �� ���� cost�� ���� ��� ����.
		int distance = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		//�ִ� �Ÿ��� �ƴ� ��� ��ŵ
		if (distances[startIndex][current] < distance) continue;

		// 4. �ش� ��带 ���ļ� Ư���� ���� ���� ��츦 ����Ͽ� �ּ� ����� ����.
		// ���� ����� ����� ���� ���� cost�� ���� ����� ����� ������ Ȯ��
		for (int i = 0; i < graph[current].size(); i++)
		{
			// ���õ� ��带 ���� ���� ���ļ� ���� ���
			int nextDistance = distance + graph[current][i].first;
			// ���õ� ����� ���� ���
			int next = graph[current][i].second;
			// ������ �ּ� ��뺸�� �� �����ϴٸ� ��ü.
			if (nextDistance < distances[startIndex][next])
			{
				distances[startIndex][next] = nextDistance;
				// �湮�� �� �ִ� ����̹Ƿ� �̳��鿡���� Ž�� ����
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