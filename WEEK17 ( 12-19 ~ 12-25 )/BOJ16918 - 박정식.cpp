#include <iostream>
#include <vector>

#define Y first
#define X second

using namespace std;

int R, C, N;
int map[201][201];

// ���� �¿�
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void PrintMap()
{
	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			// 0�κκ��� ��ĭ�̹Ƿ� .���� �ٲ㼭 ���
			if (map[y][x] == 0)
				cout << ".";
			// �׿ܿ� ���� ���� ��ź�̹Ƿ� 0���� �ٲ㼭 ���
			else
				cout << "O";
		}
		cout << endl;
	}
}

void Input()
{
	cin >> R >> C >> N;

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			char c;
			cin >> c;
			if (c == '.')
				map[y][x] = 0;
			else
				map[y][x] = 2;
		}
	}
}

void Explosion()
{
	// ��ź ��ǥ���� ����
	vector<pair<int, int>> v;

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			if (map[y][x] == 1)
			{
				// ������ ��ź�� ��ǥ ����
				v.push_back({ y, x });
			}
		}
	}

	while (!v.empty())
	{
		pair<int, int> cur = v.back();
		v.pop_back();
		map[cur.Y][cur.X] = 0;
		for (int i = 0; i < 4; i++)
		{
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];

			if (ny <0 || nx <0 || ny> R || nx > C)
				continue;
			// �����¿� ������ 0(��ĭ)���� �����
			map[ny][nx] = 0;
		}
	}
}

// �� ��ü�� �˻����� 0�κκ��� ��ĭ�̹Ƿ� ��ź��ġ
void CreateBomb()
{
	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			if (map[y][x] == 0)
				map[y][x] = 3;
		}
	}
}


void Solution()
{
	// ����ð� 
	// ���� 1�� ���� �������� �ƹ��͵� ���� �ʴ´�. �׷��� 1���� ����
	int currentTime = 1;

	if (N == 1)
	{
		PrintMap();
		return;
	}
	while (true)
	{		
		// ��ź�� ��ġ�Ǿ� ���� ���� ��� ĭ�� ��ź�� ��ġ�Ѵ�.
		currentTime++;
		// ����ð��� N�ʰ� �����ٸ� ����
		if (currentTime > N)
			break;

		for (int y = 0; y < R; y++)
		{
			for (int x = 0; x < C; x++)
			{
				// 2~4�� ��ź�� �ǹ��Ѵ�.
				// �� �� -1 �� ��ź�� ������ ���� ���� �ð��� �ǹ�
				if (map[y][x] > 1)
				{
					map[y][x] = map[y][x] - 1;
				}
			}
		}

		// 3�� 4�� �ݺ��Ѵ�.
		// 3. ���� 1�� ���� ��ź�� ��ġ�Ǿ� ���� ���� ��� ĭ�� ��ź�� ��ġ�Ѵ�. ��, ��� ĭ�� ��ź�� ������ �ְ� �ȴ�. ��ź�� ��� ���ÿ� ��ġ�ߴٰ� �����Ѵ�.
		if (currentTime % 2 == 0)
			CreateBomb();
		// 4. 1�ʰ� ���� �Ŀ� 3�� ���� ��ġ�� ��ź�� ��� �����Ѵ�.
		else
			Explosion();
	}
	PrintMap();
}

int main()
{
	Input();
	Solution();
	
	return 0;
}