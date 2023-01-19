#include <iostream>
#include <deque>
#include <queue>

#define Y second
#define X first

using namespace std;

int map[102][102];

// N : ��ũ��, K : ����� ����, L : ���� ���� ��ȯ Ƚ��
int N, K, L;
// �� ������ �Ʒ� ����
int dx[4] = { -1, 0, 1, 0 }; 
int dy[4] = { 0, 1, 0, -1 };
// ���⺯�� 0 : ��, 1 : ������, 2 : �Ʒ�, 3 : ���� 
int dir;
// �� ��ġ ����
deque<pair<int, int>> dqSnake;
// ���� ��ȯ ��ɾ� ����
queue<pair<int, char>> qCommands;
// �ð� ����
int currentTime = 0;

 
// �Ӹ� ȸ��
void Rotate(char command)
{
	if (command == 'D')
		dir = (dir + 1) % 4;
	else
		dir = (dir + 3) % 4;
}

void Solution()
{
	// �� �ʱⰪ 1�� 1������ ����
	map[1][1] = 1;
	dqSnake.push_front({1,1});
	// �������� ���� ����
	dir = 1;

	while (true)
	{
		currentTime++;
		// �̵����⿡ �Ӹ� ����
		pair<int, int> head = dqSnake.front();
		// �ǵڴ� ����
		pair<int, int> tail = dqSnake.back();
		head.X += dx[dir];
		head.Y += dy[dir];
		dqSnake.push_front(head);

		// �ڱ� ���� �ε�ġ�ų� ���� ���� ���ٸ�
		if (map[head.X][head.Y] == 1 ||	head.X < 1 || head.Y < 1 || head.X > N || head.Y > N)
		{
			cout << currentTime << endl;
			return;
		}

		// �̵��� ��ġ�� ����� ���ٸ�
		if (map[head.X][head.Y] != 2)
		{
			// �ʿ��� �����κ� �����ְ� dq������ ����
			map[tail.X][tail.Y] = 0;
			dqSnake.pop_back();
		}
		// �Ӹ��κ� 1�� ǥ��
		map[head.X][head.Y] = 1;
		// ������ �ٲٴ� ��ɾ ���� �ϸ鼭
		// ���� �ð��� ������ �ٲ�� �ϴ� �ð��̶�� ���⺯ȯ
		if (!qCommands.empty() && qCommands.front().first == currentTime)
		{
			Rotate(qCommands.front().second);
			qCommands.pop();
		}
	}
}

void Input()
{
	// ��ũ��
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int row, col;
		cin >> row >> col;

		// map
		// 0 = ��ĭ, 1 = ��, 2 = ������
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