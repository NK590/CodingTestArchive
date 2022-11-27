#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

constexpr auto MAX = 51;

int N, M; 
int startX, startY; 
char map[MAX][MAX];
bool checkMap[MAX][MAX][1 << 6] = { false };

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };



typedef struct myStruct {
	int x, y;
	int checkKey = 0;
	int cnt = 0;
};

myStruct tempStruct;
queue<myStruct> myQueue;



void Initalization()
{
	cin >> N >> M;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			map[i][j] = '#';
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '0')
			{
				startY = i;
				startX = j;
			}
		}
	}
}

int BFS()
{
	myStruct mystruct;
	map[startY][startX] = '.';
	mystruct.x = startX;
	mystruct.y = startY;
	myQueue.push(mystruct);
	while (!myQueue.empty())
	{
		tempStruct = myQueue.front();
		tempStruct.cnt = myQueue.front().cnt + 1;
		myQueue.pop();
		for (int k = 0; k < 4; k++)
		{
			mystruct = tempStruct;
			mystruct.x = tempStruct.x + dx[k];
			mystruct.y = tempStruct.y + dy[k];

			if (mystruct.x <= 0 || mystruct.x > M || mystruct.y <= 0 || mystruct.y > N || map[mystruct.y][mystruct.x] == '#' 
				|| checkMap[mystruct.y][mystruct.x][tempStruct.checkKey] == true)
			{
				continue;
			}
			else if (65 <= (int)map[mystruct.y][mystruct.x] && (int)map[mystruct.y][mystruct.x] <= 90)
			{

				if ((mystruct.checkKey & 1 << ((int)map[mystruct.y][mystruct.x] - 'A')) > 0)
				{
					
					checkMap[mystruct.y][mystruct.x][mystruct.checkKey] = true;
				}
				else
				{
					continue;
				}
			}
			else if (97 <= (int)map[mystruct.y][mystruct.x] && (int)map[mystruct.y][mystruct.x] <= 122)
			{
				mystruct.checkKey = mystruct.checkKey | 1 << ((int)map[mystruct.y][mystruct.x] - 'a');
				
				
			}
			else if (map[mystruct.y][mystruct.x] == '.')
			{
				
			}
			else if (map[mystruct.y][mystruct.x] == '1')
			{
				return mystruct.cnt;
			}

			checkMap[mystruct.y][mystruct.x][mystruct.checkKey] = true;
			myQueue.push(mystruct);
		}
	}

	return -1;
}

int main()
{
	Initalization();
	cout << BFS();
	return 0;
}