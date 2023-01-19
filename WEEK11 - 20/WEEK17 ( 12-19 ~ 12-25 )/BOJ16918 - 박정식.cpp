#include <iostream>
#include <vector>

#define Y first
#define X second

using namespace std;

int R, C, N;
int map[201][201];

// 상하 좌우
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void PrintMap()
{
	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			// 0인부분은 빈칸이므로 .으로 바꿔서 출력
			if (map[y][x] == 0)
				cout << ".";
			// 그외에 값은 전부 폭탄이므로 0으로 바꿔서 출력
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
	// 폭탄 좌표저장 벡터
	vector<pair<int, int>> v;

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			if (map[y][x] == 1)
			{
				// 터지는 폭탄들 좌표 저장
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
			// 상하좌우 터져서 0(빈칸)으로 만들기
			map[ny][nx] = 0;
		}
	}
}

// 맵 전체를 검사한후 0인부분은 빈칸이므로 폭탄배치
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
	// 현재시간 
	// 다음 1초 동안 봄버맨은 아무것도 하지 않는다. 그래서 1부터 시작
	int currentTime = 1;

	if (N == 1)
	{
		PrintMap();
		return;
	}
	while (true)
	{		
		// 폭탄이 설치되어 있지 않은 모든 칸에 폭탄을 설치한다.
		currentTime++;
		// 현재시간이 N초가 지났다면 종료
		if (currentTime > N)
			break;

		for (int y = 0; y < R; y++)
		{
			for (int x = 0; x < C; x++)
			{
				// 2~4은 폭탄을 의미한다.
				// 각 값 -1 은 폭탄이 터지기 까지 남은 시간을 의미
				if (map[y][x] > 1)
				{
					map[y][x] = map[y][x] - 1;
				}
			}
		}

		// 3과 4를 반복한다.
		// 3. 다음 1초 동안 폭탄이 설치되어 있지 않은 모든 칸에 폭탄을 설치한다. 즉, 모든 칸은 폭탄을 가지고 있게 된다. 폭탄은 모두 동시에 설치했다고 가정한다.
		if (currentTime % 2 == 0)
			CreateBomb();
		// 4. 1초가 지난 후에 3초 전에 설치된 폭탄이 모두 폭발한다.
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