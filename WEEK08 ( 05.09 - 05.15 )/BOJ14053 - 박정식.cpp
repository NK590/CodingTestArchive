#include <iostream>
#include <queue>

using namespace std;

struct ROBOT
{
	int y, x, dir;
};

int map[51][51];

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, m;
	ROBOT robot;

	cin >> n >> m;
	cin >> robot.y >> robot.x >> robot.dir;

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			cin >> map[y][x];
		}
	}

	queue<ROBOT> q;
	q.push(robot);
	int result = 0;

	while (!q.empty())
	{
		ROBOT current = q.front(); 
		q.pop();
		if (map[current.y][current.x] == 0)
		{
			map[current.y][current.x] = 2;
			++result;
		}

		for (int direction = 0; direction < 4; ++direction)
		{
			ROBOT next;
			next.dir = (current.dir + 3 - direction) % 4;
			next.y = current.y + dy[next.dir];
			next.x = current.x + dx[next.dir];

			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m
				|| map[next.y][next.x] != 0)
			{
				continue;
			}

			q.push(next);
			break;
		}
		if (q.empty())
		{
			ROBOT next;
			next.dir = current.dir;
			next.y = current.y + dy[(next.dir + 2) % 4];
			next.x = current.x + dx[(next.dir + 2) % 4];			

			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m
				|| map[next.y][next.x] == 1)
			{
				break;
			}
			q.push(next);
		}
	}

	cout << result << endl;


	return 0;
}