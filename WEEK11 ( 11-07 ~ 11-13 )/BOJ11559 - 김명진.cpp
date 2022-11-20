#include<iostream>
#include<queue>

using namespace std;

char board[12][6];
bool visit[12][6];
bool isBoom[12][6];
int continuity = 0;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void Gravity() 
{ 
	for (int i = 11; i >= 0; i--) 
	{
		for (int j = 5; j >= 0; j--) 
		{
			int dist = 0;
			if (board[i][j] == '.') 
			{
				for (int k = i; k >= 0; k--)
				{
					if (board[k][j] == '.')
					{
						dist++;
					}
					else 
					{
						while (dist--) 
						{
							board[k + 1][j] = board[k][j];
							board[k][j] = '.';
							k++;
						}
						break;
					}
				}
			}
		}
	}
}

void explode()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (isBoom[i][j] == true) 
			{
				board[i][j] = '.';
			}
		}
	}
}

int bfs(int y, int x) 
{
	queue<pair<int, int>> q;
	queue<pair<int, int>> candidate;
	q.push({y,x});
	candidate.push({ y,x });
	visit[y][x] = true;
	char color = board[y][x];
	int cnt = 1;
	while (!q.empty()) 
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) 
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			char new_color = board[ny][nx];
			if (0 <= nx && nx < 6 && 0 <= ny && ny < 12 && !visit[ny][nx] && new_color == color) 
			{
				visit[ny][nx] = true;
				q.push({ ny,nx });
				candidate.push({ ny,nx });
				cnt++;
			}
		}
	}

	if (candidate.size() >= 4)
	{
		int repeat = candidate.size();
		for (int i = 0; i < repeat; ++i)
		{
			isBoom[candidate.front().first][candidate.front().second] = true;
			candidate.pop();
		}
	}
	return cnt;
}

int main() 
{
	for (int i = 0; i < 12; i++) 
	{
		for (int j = 0; j < 6; j++) 
		{
			cin >> board[i][j];
		}
	}
	bool is_explode = true;
	while (is_explode)
	{
		int puyoSize = 0;
		is_explode = false;
		for (int i = 0; i < 12; i++) 
		{
			for (int j = 0; j < 6; j++) 
			{
				if (board[i][j] != '.' && !visit[i][j])
				{
					puyoSize = bfs(i, j);
					if (puyoSize >= 4)
					{ 
						explode();
						is_explode = true;
					}
				}
			}
		}
		if (is_explode) continuity++;

		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				visit[i][j] = false;
				isBoom[i][j] = false;
			}
		}
		Gravity();
	}
	cout << continuity;
}