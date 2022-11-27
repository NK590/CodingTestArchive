#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int N, M, V;
bool map[1001][1001]; //이어지면 1 아니면 0
bool visited[1001]; //방문한적 있으면 1 아니면 0
stack<int> s;
queue<int> q;

void DFS()
{
	visited[V] = 1;
	cout << V;
	for (int i = 0; i < N; i++)
	{
		if (map[V][N-i] == 1)
		{
			s.push(N-i);
		}
	}
	while (s.size() != 0)
	{
		int cur;
		cur = s.top();
		s.pop();
		if (visited[cur] == 0)
		{
			cout << " " << cur;
			visited[cur] = 1;
		}

		for (int i = 0; i < N; i++)
		{
			if (map[cur][N-i] == 1 && visited[N-i] == 0)
			{
				s.push(N-i);
			}
		}
	}
	cout << "\n";
}

void BFS()
{
	visited[V] = 1;
	cout << V;
	for (int i = 0; i < N; i++)
	{
		if (map[V][i+1] == 1)
		{
			q.push(i+1);
		}
	}
	while (q.size() != 0)
	{
		int cur;
		cur = q.front();
		q.pop();
		if (visited[cur] == 0)
		{
			cout << " " << cur;
			visited[cur] = 1;
		}

		for (int i = 0; i < N; i++)
		{
			if (map[cur][i+1] == 1 && visited[i+1] == 0)
			{
				q.push(i+1);
			}
		}
	}
}

int main()
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		visited[i + 1] = 0;
	}

	DFS();

	for (int i = 0; i < N; i++)
	{
		visited[i + 1] = 0;
	}

	BFS();
}