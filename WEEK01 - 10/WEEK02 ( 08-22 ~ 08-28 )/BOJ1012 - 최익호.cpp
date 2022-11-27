#include <iostream>
#include <stack>
#include <queue>

using namespace std;
#define MAX 51

int Z, N, M, K, cnt; 
int result = 0;

// 현제 좌표를 표현하려고 사용
struct Point {

	int x, y;

};


int D[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
			   //  상       하      좌       우

int map[MAX][MAX];
bool isVisited[MAX][MAX];
queue<int> myQueue;

// 초기화
void Init()
{
	cin >> M >> N >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			map[i][j] = 0;
			isVisited[i][j] = false;
		}
	}

	for (; K >= 1; K--)
	{
		int x, y;
		cin >> x >> y;
		map[y][x] = 1;

	}
}

void DFS(int x, int y)
{
	result++;
	stack<Point> mystack;
	mystack.push({ x, y });

	while(!mystack.empty())
	{
		Point curr = mystack.top();
		mystack.pop();

		if (isVisited[curr.x][curr.y])
		{
			continue;
		}

		isVisited[curr.x][curr.y] = true;
		map[curr.x][curr.y] = 4;

		for (int i = 0; i < 4; i++)
		{
			int nx = curr.x + D[i][0];
			int ny = curr.y + D[i][1];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			{
				continue;
			}

			if (isVisited[nx][ny])
			{
				continue;
			}

			if (map[nx][ny] == 0)
			{
				continue;
			}

			mystack.push({ nx, ny });

		}
	}
}


int main()
{
	cin >> Z;

	while (Z > 0)
	{
		Init();

	 /* 시각적으로 확인하기 위함 코드
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				std::cout << map[i][j] << ' ';
			}
	
			std::cout << "\n";
		}
	 */
		result = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 1 && isVisited[i][j] == false)
				{
					DFS(i, j);

				}
			}
		}

		myQueue.push(result);

		Z--;
	}

	while (!myQueue.empty())
	{
		cnt = myQueue.front();
		myQueue.pop();
		cout << cnt << "\n";
	}

	return 0;
}