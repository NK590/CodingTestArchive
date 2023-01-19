#include <iostream>
#include <vector>

#define X first
#define Y second
using namespace std;

struct Robot
{
	int x;
	int y;
	int dir;
};
struct Command
{
	int index;
	char type;
	int count;
};

Robot robots[101];
Command commands[101];
int map[101][101];

int w, h;
int N, M;

// �� ������ �Ʒ� ����
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void Solution()
{
	for (int i = 0; i < M; i++)
	{
		// ȸ��, ������� ����
		char commandType = commands[i].type;
		// �ش� ����� ��� ������ ������
		int count = commands[i].count;
		// ����� ���� �κ� index
		int index = commands[i].index;
		for (int j = 0; j < count; j++)
		{
			if (commandType == 'L')
				robots[index].dir = (robots[index].dir + 3) % 4;
			else if (commandType == 'R')
				robots[index].dir = (robots[index].dir + 1) % 4;
			else if(commandType == 'F')
			{
				int nx = robots[index].x + dx[robots[index].dir];
				int ny = robots[index].y + dy[robots[index].dir];
				map[robots[index].x][robots[index].y] = 0;
				// �̵��� ��ǥ�� ���� ����ٸ�
				if (nx == 0 || ny == 0 || nx > w || ny > h)
				{
					cout << "Robot " << index << " crashes into the wall";
					return;
				}
				// �̵��� ��ǥ�� ������� �ƴ϶��
				if (map[nx][ny] != 0)
				{
					cout << "Robot " << index << " crashes into robot " << map[nx][ny];
					return;
				}
				robots[index].x = nx;
				robots[index].y = ny;
				map[nx][ny] = index;
			}
		}
	}
	// ������� �Ϸ�
	cout << "OK" << endl;

}

void Input()
{
	cin >> w >> h;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		int x, y, dir = 0;
		char cdir;
		cin >> x >> y >> cdir;
		if (cdir == 'N')
			dir = 0;
		else if (cdir == 'E')
			dir = 1;
		else if (cdir == 'S')
			dir = 2;
		else if (cdir == 'W')
			dir = 3;
		robots[i] = { x, y, dir };
		map[x][y] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int index, count;
		char type;
		cin >> index >> type >> count;

		commands[i] = { index, type, count };
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();
	Solution();

	return 0;
}