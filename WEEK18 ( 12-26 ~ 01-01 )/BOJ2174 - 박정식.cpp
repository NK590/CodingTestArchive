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

// 위 오른쪽 아래 왼쪽
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void Solution()
{
	for (int i = 0; i < M; i++)
	{
		// 회전, 전진명령 구분
		char commandType = commands[i].type;
		// 해당 명령을 몇번 수행할 것인지
		int count = commands[i].count;
		// 명령을 내릴 로봇 index
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
				// 이동할 좌표가 맵을 벗어난다면
				if (nx == 0 || ny == 0 || nx > w || ny > h)
				{
					cout << "Robot " << index << " crashes into the wall";
					return;
				}
				// 이동할 좌표가 빈공간이 아니라면
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
	// 정상수행 완료
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