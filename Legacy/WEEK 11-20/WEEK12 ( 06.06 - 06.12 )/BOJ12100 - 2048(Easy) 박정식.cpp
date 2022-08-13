#include <iostream>
#pragma warning(disable: 4996)

using namespace std;

int n, result;

struct BOARD
{
	int map[20][20];

	// ���� 90���� ȸ��
	void Rotate()
	{
		int temp[20][20];

		for (int y = 0; y < n; ++y)
		{
			for (int x = 0; x < n; ++x)
			{
				temp[y][x] = map[n - x - 1][y];
			}
		}

		for (int y = 0; y < n; ++y)
		{
			for (int x = 0; x < n; ++x)
			{
				map[y][x] = temp[y][x];
			}
		}
	}

	// ���� �� ���� �ִ밪ã��
	int GetMax()
	{
		for (int y = 0; y < n; ++y)
		{
			for (int x = 0; x < n; ++x)
			{
				if (result < map[y][x])
				{
					result = map[y][x];
				}
			}
		}
		return result;
	}

	// �ʿ� �����͸� �ø��� �۾��� �մϴ�.
	// 90���� ����ü�� ������ ������ ���ʿ����ʾƷ� �̵� �Լ��� �ʿ� ����
	void Up()
	{
		int temp[20][20];

		for (int x = 0; x < n; ++x)
		{
			// �Ʒ��� �����Ϳ� ���ؼ� �������̸鼭 �̹� ��������(flag�� Ȯ��)�� �������� *2�����ݴϴ�
			// ���� �̵��� ��ų �ű⶧���� target�� -1
			int flag = 0, target = -1;
			for (int y = 0; y < n; ++y)
			{
				if (map[y][x] == 0)
				{
					continue;
				}
				if (flag == 1 && map[y][x] == temp[target][x])
				{
					temp[target][x] *= 2;
					flag = 0;
				}
				else
				{
					temp[++target][x] = map[y][x];
					flag = 1;
				}
			}
			for (++target; target < n; ++target)
			{
				temp[target][x] = 0;
			}
		}
		for (int y = 0; y < n; ++y)
		{
			for (int x = 0; x < n; ++x)
			{
				map[y][x] = temp[y][x];
			}
		}
	}
};

void dfs(BOARD cur, int count)
{
	if (count == 5)
	{
		int candi = cur.GetMax();
		if (result < candi)
		{
			result = candi;
		}
		return;
	}
	for (int dir = 0; dir < 4; ++dir)
	{
		BOARD next = cur;
		next.Up();
		dfs(next, count + 1);
		cur.Rotate();
	}
}

int main()
{
	BOARD board;
	scanf("%d", &n);

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			scanf("%d", &board.map[y][x]);
		}
	}

	result = 0;
	dfs(board, 0);
	printf("%d\n", result);

	return 0;
}