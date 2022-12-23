#include <iostream>
#include <deque>
#include <queue>

#define Y second
#define X first

using namespace std;

int map[102][102];

// N : 맵크기, K : 사과의 개수, L : 뱀의 방향 변환 횟수
int N, K, L;
// 위 오른쪽 아래 왼쪽
int dx[4] = { -1, 0, 1, 0 }; 
int dy[4] = { 0, 1, 0, -1 };
// 방향변수 0 : 위, 1 : 오른쪽, 2 : 아래, 3 : 왼쪽 
int dir;
// 뱀 위치 저장
deque<pair<int, int>> dqSnake;
// 방향 변환 명령어 저장
queue<pair<int, char>> qCommands;
// 시간 변수
int currentTime = 0;

 
// 머리 회전
void Rotate(char command)
{
	if (command == 'D')
		dir = (dir + 1) % 4;
	else
		dir = (dir + 3) % 4;
}

void Solution()
{
	// 뱀 초기값 1행 1열부터 시작
	map[1][1] = 1;
	dqSnake.push_front({1,1});
	// 오른쪽을 보고 시작
	dir = 1;

	while (true)
	{
		currentTime++;
		// 이동방향에 머리 생성
		pair<int, int> head = dqSnake.front();
		// 맨뒤는 꼬리
		pair<int, int> tail = dqSnake.back();
		head.X += dx[dir];
		head.Y += dy[dir];
		dqSnake.push_front(head);

		// 자기 몸통 부딪치거나 맵을 벗어 난다면
		if (map[head.X][head.Y] == 1 ||	head.X < 1 || head.Y < 1 || head.X > N || head.Y > N)
		{
			cout << currentTime << endl;
			return;
		}

		// 이동한 위치에 사과가 없다면
		if (map[head.X][head.Y] != 2)
		{
			// 맵에서 꼬리부분 없애주고 dq에서도 삭제
			map[tail.X][tail.Y] = 0;
			dqSnake.pop_back();
		}
		// 머리부분 1로 표시
		map[head.X][head.Y] = 1;
		// 방향을 바꾸는 명령어가 존재 하면서
		// 현재 시간이 방향을 바꿔야 하는 시간이라면 방향변환
		if (!qCommands.empty() && qCommands.front().first == currentTime)
		{
			Rotate(qCommands.front().second);
			qCommands.pop();
		}
	}
}

void Input()
{
	// 맵크기
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int row, col;
		cin >> row >> col;

		// map
		// 0 = 빈칸, 1 = 뱀, 2 = 아이템
		map[row][col] = 2;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int endTime;
		char cDir;
		cin >> endTime >> cDir;

		qCommands.push({endTime, cDir});
	}
}

int main()
{
	Input();
	Solution();

	return 0;
}