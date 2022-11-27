#include<iostream>
#include<stack>

using namespace std;

#define MAX 101

int N, M, K, cnt , result; // 가로,세로,쓰레기의 개수 // 최대 개수

// 좌표를 표현
struct Point {

	int x, y;

};


int D[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
               //  상       하      좌       우

char map[MAX][MAX];
bool isVisited[MAX][MAX];

// 초기화
void Init()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			map[i][j] = '.';
			isVisited[i][j] = false;
		}
	}

	//음식물의 개수 만큼 입력을 받음
	for (; K >= 1; K--)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] ='#';
		// 음식물이 있는 곳 #
	}
}

void DFS(int x, int y)
{
	stack<Point> mystack;
	mystack.push({ x, y });


	while(!mystack.empty())
	{

		Point curr = mystack.top();
		mystack.pop();


		// 방문 했다면 넘김
		if (isVisited[curr.x][curr.y])
		{
			continue;
		}

		// 방문 마킹
		isVisited[curr.x][curr.y] = true;
		cnt++;

		for (int i = 0; i < 4; i++)
		{
			// 상하 좌우로 검색
			int nx = curr.x + D[i][0];
			int ny = curr.y + D[i][1];

			// 범위를 벗어낫을 경우에 넘김
			if (nx <= 0 || nx > N || ny <= 0 || ny > M)
			{
				continue;
			}

			if (isVisited[nx][ny])
			{
				continue;
			}

			if (map[nx][ny] == '.')
			{
				continue;
			}

			
			mystack.push({ nx, ny });
			
		}
	}
}


int main()
{
	cin >> N >> M >> K;

	// 초기화
	Init();


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			std::cout << map[i][j] << ' ';
		}

		std::cout << "\n";
	}

	

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			// 음식물이 있고 방문한 적이 없을 경우 실행
			if (map[i][j] == '#' && isVisited[i][j] == false)
			{
				cnt = 0;
				DFS(i, j);
				if (result < cnt)
				{
					result = cnt;
				}
			}
		}
	}

	std::cout << result;

	return 0;
}