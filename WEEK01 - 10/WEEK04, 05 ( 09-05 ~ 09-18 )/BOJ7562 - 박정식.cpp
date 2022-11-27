#define MAX 300 + 1
#define Y first
#define X second
#include <iostream>
#include <queue>

using namespace std;


// ����Ʈ�� Ž�� ���� �Ϲ����� �����¿찡 �ƴϿ���.
// https://www.acmicpc.net/problem/7562
// �� 8�����̵� �ϴϱ� �迭�� 8�� ������ֱ�
// �»�ܺ��� ���ܼ����� �־����
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int map[MAX][MAX];
// I : ü������ ũ��� I*I �̿���
int I;
queue<pair<int, int>> q;

void reset()
{
	for (int y = 0; y < I; y++)
	{
		for (int x = 0; x < I; x++)
		{
			map[y][x] = 0;
		}
	}

	while (!q.empty())
		q.pop();
}

void Bfs(int y, int x)
{
	if (map[y][x] == -1)
	{
		map[y][x] = 0;
		return;
	}
	

	q.push({y, x});
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		

		for (int dir = 0; dir < 8; dir++)
		{
			int ny = cur.Y + dy[dir];
			int nx = cur.X + dx[dir];

			// Ž�� ������ ���� ����ٸ� ��ŵ
			if (ny < 0 || nx < 0 || ny >= I || nx >= I)
				continue;
			// ���� ������ ã�Ҵٸ� ���� �ʿ� �ɸ� �ð����� 1�� ���ϰ� �Լ��� �ٷ� ������.
			if (map[ny][nx] == -1)
			{
				map[ny][nx] = map[cur.Y][cur.X];
				return;
			}
			// �̹� �湮�� �����̶�� ��ŵ�Ѵ�
			if (map[ny][nx] != 0)
				continue;

			map[ny][nx] = map[cur.Y][cur.X] + 1;
			q.push({ny, nx});
				
		}
	}
}

int main()
{
	// t : �׽�Ʈ���̽� ����
	int t;
	cin >> t;

	// �׽�Ʈ���̽� ������ŭ ����
	for (int i = 0; i < t; i++)
	{
		cin >> I;

		// ����Ʈ ���� ����
		int startY, startX;
		cin >> startY >> startX;
		// ����Ʈ ���� ����
		int endY, endX;
		cin >> endY >> endX;

		// ���� ������ 1���� ����
		map[startY][startX] = 1;
		map[endY][endX] = -1;

		Bfs(startY, startX);
		cout << map[endY][endX] << "\n";
		reset();
	}

	return 0;
}