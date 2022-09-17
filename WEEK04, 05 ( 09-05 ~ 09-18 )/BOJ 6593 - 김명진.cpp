#include <iostream>
#include <queue>

using namespace std;

const int MAX = 30;
int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int main()
{
	int L, R, C;
	while (true)
	{
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;
		queue<pair<int, pair<int, int>>> q;
		char buliding[MAX][MAX][MAX];
		int isBlocked[MAX][MAX][MAX];
		int distance[MAX][MAX][MAX];
		bool isVisited[MAX][MAX][MAX];

		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				for (int k = 0; k < C; k++)
				{
					isBlocked[i][j][k] = 0;
					distance[i][j][k] = 0;
					isVisited[i][j][k] = false;
				}
			}
		}
		bool isEscape = false;
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				for (int k = 0; k < C; k++)
				{
					char temp;
					cin >> temp;
					buliding[i][j][k] = temp;

					if (temp == 'S')
					{
						isVisited[i][j][k] = true;
						q.push({ i, {j,k} });
					}
					else if (temp == '#')
					{
						isBlocked[i][j][k] = 1;
					}
				}
			}
		}

		while (q.size() != 0)
		{
			if (isEscape) break;
			auto cur = q.front();
			q.pop();
			for (int i = 0; i < 6; i++)
			{
				int nx = cur.second.first + dx[i];
				int ny = cur.second.second + dy[i];
				int nz = cur.first + dz[i];
				if (nx < 0 || ny < 0 || nz < 0 || nx >= R || ny >= C || nz >= L) continue;
				if (isVisited[nz][nx][ny] == true || isBlocked[nz][nx][ny] == 1) continue;
				distance[nz][nx][ny] = distance[cur.first][cur.second.first][cur.second.second] + 1;

				if (buliding[nz][nx][ny] == 'E')
				{
					cout << "Escaped in " << distance[nz][nx][ny] << " minute(s)." << "\n";
					isEscape = true;
					break;
				}
				q.push({ nz,{nx,ny} });
				isVisited[nz][nx][ny] = 1;
			}
		}
		while (q.size() != 0)
		{
			q.pop();
		}
		if (!isEscape)
		{
			cout << "Trapped!" << "\n";
		}
	}
	return 0;
}