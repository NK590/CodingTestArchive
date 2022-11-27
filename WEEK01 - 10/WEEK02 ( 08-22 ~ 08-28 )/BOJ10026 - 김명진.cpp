#include <iostream>
#include <stack>;
#include <vector>;
#include <utility>;

using namespace std;

int N;
int adj[100][100];
int vis[100][100];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void VisReset()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			vis[i][j] = false;
		}
	}
}

int dfs()
{
	VisReset();
	int ret = 0;
	stack<pair<int,int>> s;
	for (int i = 0; i < N; i++)
	{
		for (int j =0; j<N; j++)
		{
			if (vis[i][j]) continue; 
			ret++; 
			
			s.push(make_pair(i, j));
			vis[i][j] = true;

			while (!s.empty())
			{
				pair<int, int> cur = s.top();

				s.pop();

				for (int k = 0; k < 4; k++)
				{
					pair<int, int> nxt;
					nxt.first = cur.first + dy[k];
					nxt.second = cur.second + dx[k];

					if (nxt.first < 0 || nxt.first >= N || nxt.second < 0 || nxt.second >= N) continue;

					if (vis[nxt.first][nxt.second]) continue;

					if (adj[nxt.first][nxt.second] == adj[cur.first][cur.second])
					{
						s.push(nxt);
						vis[nxt.first][nxt.second] = true;
					}
				}
			}
		}
	}
	return ret;
}

int dfsRG()
{
	VisReset();
	int ret = 0;
	stack<pair<int, int>> s;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (vis[i][j]) continue; 
			ret++;

			s.push(make_pair(i, j));
			vis[i][j] = true;

			while (!s.empty())
			{
				pair<int, int> cur = s.top();

				s.pop();

				for (int k = 0; k < 4; k++)
				{
					pair<int, int> nxt;
					nxt.first = cur.first + dy[k];
					nxt.second = cur.second + dx[k];

					if (nxt.first < 0 || nxt.first >= N || nxt.second < 0 || nxt.second >= N) continue;

					if (vis[nxt.first][nxt.second]) continue;

					if (adj[cur.first][cur.second] == 1 || adj[cur.first][cur.second] == 2)
					{
						if (adj[nxt.first][nxt.second] == 1 || adj[nxt.first][nxt.second] == 2)
						{
							s.push(nxt);
							vis[nxt.first][nxt.second] = true;
						}
					}
					else
					{
						if (adj[nxt.first][nxt.second] == 3)
						{
							s.push(nxt);
							vis[nxt.first][nxt.second] = true;
						}
					}
				}
			}
		}
	}
	return ret;
}
int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		for (int j = 0; j < N; j++)
		{
			switch (a[j])
			{
			case 'R':
				adj[i][j] = 1;
				break;
			case 'G':
				adj[i][j] = 2;
				break;
			case 'B':
				adj[i][j] = 3;
				break;
			default:
				cout << "Wrong Input";
			}
		}
	}
	cout << dfs() << " " << dfsRG();
}
