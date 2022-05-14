#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int r, c;
string arr[21];
int cnt = 0;
int ans = -1;
int visited[27];

const int dy[] = { 1, -1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };

void dfs(int x, int y)
{
	int ax, ay;

	visited[arr[x][y] - 'A'] = 1;
	cnt++;
	ans = max(ans, cnt);

	for (int index = 0; index < 4; index++)
	{
		ax = x + dx[index];
		ay = y + dy[index];

		if ((ax >= 0 && ax < r) && (ay >= 0 && ay < c))
		{
			if ((!visited[arr[ax][ay] - 'A']))
			{
				dfs(ax, ay);
				visited[arr[ax][ay] - 'A'] = 0;
				cnt--;
			}
		}

	}


}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;

	for (int index = 0; index < r; index++)
	{
		cin >> arr[index];
	}

	dfs(0, 0);

	cout << ans << endl;

	return 0;
}