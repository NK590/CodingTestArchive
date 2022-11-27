#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
vector<int> adj[100];
int vis[100];

void VisReset()
{
	for (int i = 0; i < N; i++)
	{
		vis[i] = false;
	}
}

void dfs()
{
	stack<int> s;

	for (int i = 0; i < N; i++)
	{
		VisReset();

		s.push(i);

		while (!s.empty())
		{
			int cur = s.top();
			s.pop();

			for (int j = 0; j < adj[cur].size(); j++)
			{
				int nxt = adj[cur][j];
				if (vis[nxt]) continue;

				s.push(nxt);
				vis[nxt] = true;
			}
		}
		for (int k = 0; k < N; k++)
		{
			cout << vis[k] <<" ";
		}
		cout << "\n";
	}
}

int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			if (a)
			{
				adj[i].push_back(j);
			}
		}
	}
	VisReset();
	dfs();
}