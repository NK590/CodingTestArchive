#include <iostream>
#include <list>

using namespace std;
constexpr auto MAX = 101;

// 0 빈공간 
// 1 ~ 100 로봇 
int map[MAX][MAX];

// A : 가로의 길이, B : 세로의 길이
int A, B, N, M;

// 명령어 구조체
struct Command
{
	int robotNumber; // 로봇의 번호
	char orderDir; // 로봇이 움직일 방향
	int repetition; // 반복 횟수
} CS[100];

// 명령들을 저장할 리스트를 생성
list<Command> CommandList;
list<Command>::iterator iterCommandList;

// 로봇의 위치와 방향을 저장
struct robotPos
{
	int x, y;
	int dir;

} RP[100];

// E N W S
int dirXY[4][2] = { {1, 0}, {0,1}, {-1,0}, {0,-1} };

bool debug = false;

// 디버그 확인용 함수
void DebugMap()
{
	cout << "\n";
	// 맵 출력
	for (int i = 1; i < MAX; i++)
	{
		for (int j = 1; j < MAX; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	// 명령 확인
	for (iterCommandList = CommandList.begin(); iterCommandList != CommandList.end(); iterCommandList++)
	{
		cout << "\n" << "robotNumber : " << iterCommandList->robotNumber << " orderDir : " 
			<< iterCommandList->orderDir << "  repetition : " << iterCommandList->repetition;
	}

}

// 방향을 정수로 변환해주는 함수
int ChangeDirCharToInt(char ch)
{
	int temp = 0;
	switch (ch)
	{
		case 'E':
			temp = 0;
			break;
		case 'N':
			temp = 1;
			break;
		case 'W':
			temp = 2;
			break;
		case 'S':
			temp = 3;
			break;
	}

	return temp;
}

// 초기화를 위한 함수입니다.
void Initialization()
{
	// 맵을 전부 빈공간으로 만들어줍니다.
	for (int i = 1; i < MAX; i++)
	{
		for (int j = 1; j < MAX; j++)
		{
			map[i][j] = 0;
		}
	}
}

// 입력을 받는 함수 입니다.
void ReceiveInput()
{

	cin >> A >> B >> N >> M;

	int Number = 1;
	int tempOne, tempTwo;
	char tempChar;

	// 로봇의 초기 좌표와 방향을 입력받습니다.
	while (N > 0)
	{
		cin >> tempOne >> tempTwo >> tempChar;
		map[tempOne][tempTwo] = Number;
		RP[Number - 1].x = tempOne;
		RP[Number - 1].y = tempTwo;
		RP[Number - 1].dir = ChangeDirCharToInt(tempChar);
		Number++;
		N--;
	}

	Number = 0;

	// 명령들을 구조체 리스트에 넣습니다.
	while (M > 0)
	{
		cin >> tempOne >> tempChar >> tempTwo;
		CS[Number].robotNumber = tempOne;
		CS[Number].orderDir = tempChar;
		CS[Number].repetition = tempTwo;
		CommandList.push_back(CS[Number]);
		Number++;
		M--;
	}

}

// 시뮬레이션 시작
void SimulationStart()
{
	int cnt, number, tempX, tempY, tempdir;

	// 명령 리스트를 순회
	for (iterCommandList = CommandList.begin(); iterCommandList != CommandList.end(); iterCommandList++)
	{
		cnt = iterCommandList->repetition;
		number = iterCommandList->robotNumber - 1;
		tempX = RP[number].x;
		tempY = RP[number].y;
		tempdir = RP[number].dir;

		while (cnt > 0)
		{
			switch (iterCommandList->orderDir)
			{
				case 'L': 	// L: 로봇이 향하고 있는 방향을 기준으로 왼쪽으로 90도 회전한다.
					RP[number].dir ++;
					if (RP[number].dir >= 4)
					{
						RP[number].dir = 0;
					}
					break;

				case 'R':	// R: 로봇이 향하고 있는 방향을 기준으로 오른쪽으로 90도 회전한다.
					RP[number].dir--;
					if (RP[number].dir <= -1)
					{
						RP[number].dir = 3;
					}
					break;

				case 'F':	// F : 로봇이 향하고 있는 방향을 기준으로 앞으로 한 칸 움직인다.
					tempdir = RP[number].dir;
					map[tempX][tempY] = 0;
					tempX += dirXY[tempdir][0];
					tempY += dirXY[tempdir][1];

					// 로봇이 벽에 부딪힐 경우 또는 범위를 벗어날 경우 결과 출력
					if (tempX <= 0 || tempY <= 0 || tempX > A || tempY > B)
					{
						cout << "Robot "<< number + 1 <<" crashes into the wall";
						return;
					}
					else if (map[tempX][tempY] > 0) // 로봇끼리 부딪힐 경우
					{
						cout << "Robot " << number + 1 << " crashes into robot "<< map[tempX][tempY];
						return;
					}
					else // 빈공간일경우 로봇의 위치를 바꾸어주고 맵에 로봇을 표시
					{
						RP[number].x = tempX;
						RP[number].y = tempY;
						map[tempX][tempY] = number + 1;
					}

					break;

				default:
					cout << "이 값이 나오면 안됨";
					break;
			}

			cnt--;
		}
	}

	cout << "OK";

}

int main()
{
	Initialization();
	ReceiveInput();
	SimulationStart();
	if (debug) { DebugMap(); }

	return 0;
}