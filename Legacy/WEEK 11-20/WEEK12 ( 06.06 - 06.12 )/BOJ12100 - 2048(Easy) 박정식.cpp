#include <iostream>
#pragma warning(disable: 4996)

using namespace std;

int n, result;

struct BOARD
{
	int map[20][20];

	// 맵을 90도씩 회전
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

	// 맵을 다 돌며 최대값찾기
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

	// 맵에 데이터를 올리는 작업만 합니다.
	// 90도씩 맵자체를 돌리기 때문에 왼쪽오른쪽아래 이동 함수는 필요 없음
	void Up()
	{
		int temp[20][20];

		for (int x = 0; x < n; ++x)
		{
			// 아래쪽 데이터와 비교해서 같은값이면서 이미 합쳐진적(flag로 확인)이 없을때만 *2씩해줍니다
			// 위쪽 이동만 시킬 거기때문에 target은 -1
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