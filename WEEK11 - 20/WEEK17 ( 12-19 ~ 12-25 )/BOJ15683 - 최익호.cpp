#include <iostream>

using namespace std;

constexpr auto MAX = 8;

int map[MAX][MAX];

// N 세로, M 가로
int N, M, MinBlindSpot;

bool debugBool = false;

// 우 상 좌 하
int dxdy[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };

// CCTV의 타입은 기본으로 -1
struct CCTVInformation
{
	int type = -1;
	int x = 0;
	int	y = 0;

} CCTV[MAX];

// 시각적인 디버그용 함수
void DebugPrint()
{
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
	for (int i = 0; i < MAX; i++) {
		if (CCTV[i].type != -1)
		{
			cout << "CCTV[i].type : " << CCTV[i].type << " CCTV[i].x : " << CCTV[i].x << " CCTV[i].y : " << CCTV[i].y << "\n";
		}
	}
}

// 프로그램 시작시 초기화
void Initialization()
{
	MinBlindSpot = 64;

	// 맵의 모든 부분을 빈 공간으로 초기화 시켜줍니다.
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			map[i][j] = 0;
		}
	}
}

// 문제의 입력을 받습니다.
void ReceiveInput()
{
	cin >> N >> M;
	
	// CCTV 숫자를 위한 임시
	int temp = 0;
	int	temp2 = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp2;

			if (temp2 == 6) {
				map[i][j] = -1;
			}
			else {
				map[i][j] = temp2;
			}
			

			if (temp2 > 0 && temp2 != 6) {
				CCTV[temp].type = temp2;
				CCTV[temp].x = i;
				CCTV[temp].y = j;
				temp++;
			}

		}
	}
}

// CCTV가 타입마다 할 수 있는 행등을 구현한 함수입니다.
void MarkingMap(int dir, int CCTVNumber, int check)
{
	switch (CCTV[CCTVNumber].type) {
		case 1:	
			switch (dir) {
				case 0: // 1번 타입 카메라 우측 감시 또는 해제
					for (int i = CCTV[CCTVNumber].y + 1 ; i < M; i++) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
					break;

				case 1: // 1번 타입 카메라 좌측 감시 또는 해제
					for (int i = CCTV[CCTVNumber].y - 1; i >= 0; i--) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
					break;

				case 2: // 1번 타입 카메라 아래 감시 또는 해제
					for (int i = CCTV[CCTVNumber].x + 1; i < N; i++) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					break;

				case 3: // 1번 타입 카메라 위 감시 또는 해제
					for (int i = CCTV[CCTVNumber].x - 1; i >= 0; i--) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					break;
			}
	 	    break;

		case 2:
			switch (dir) {
				case 0: // 2번 타입 카메라 우측 감시 또는 해제
					for (int i = CCTV[CCTVNumber].y + 1; i < M; i++) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
						// 2번 타입 카메라 좌측 감시 또는 해제
					for (int i = CCTV[CCTVNumber].y - 1; i >= 0; i--) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
					break;

				case 1: // 2번 타입 카메라 아래 감시 또는 해제
					for (int i = CCTV[CCTVNumber].x + 1; i < N; i++) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
						// 2번 타입 카메라 위 감시 또는 해제
					for (int i = CCTV[CCTVNumber].x - 1; i >= 0; i--) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					break;
				case 2:
					break;
				case 3:
					break;
			}
			break;

		case 3:
			switch (dir) {
				case 0: // 3번 타입 카메라 우측 감시 또는 해제
					for (int i = CCTV[CCTVNumber].y + 1; i < M; i++) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}

					// 3번 타입 카메라 위 감시 또는 해제
					for (int i = CCTV[CCTVNumber].x - 1; i >= 0; i--) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					break;

				case 1: // 3번 타입 카메라 위 감시 또는 해제
					for (int i = CCTV[CCTVNumber].x - 1; i >= 0; i--) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					// 3번 타입 카메라 좌측 감시 또는 해제
					for (int i = CCTV[CCTVNumber].y - 1; i >= 0; i--) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
					break;

				case 2: // 3번 타입 카메라 좌측 감시 또는 해제
					for (int i = CCTV[CCTVNumber].y - 1; i >= 0; i--) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
					// 3번 타입 카메라 아래 감시 또는 해제
					for (int i = CCTV[CCTVNumber].x + 1; i < N; i++) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					break;

				case 3: // 3번 타입 카메라 아래 감시 또는 해제
					for (int i = CCTV[CCTVNumber].x + 1; i < N; i++) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					// 3번 타입 카메라 우측 감시 또는 해제
					for (int i = CCTV[CCTVNumber].y + 1; i < M; i++) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
					break;
			}
			break;

		case 4:
			switch (dir) {
				case 0: 
					// 4번 타입 카메라 위 감시 또는 해제
					for (int i = CCTV[CCTVNumber].x - 1; i >= 0; i--) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}

					// 4번 타입 카메라 좌측 감시 또는 해제
					for (int i = CCTV[CCTVNumber].y - 1; i >= 0; i--) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
					// 4번 타입 카메라 아래 감시 또는 해제
					for (int i = CCTV[CCTVNumber].x + 1; i < N; i++) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					break;
				case 1: // 4번 타입 카메라 우측 감시 또는 해제
					for (int i = CCTV[CCTVNumber].y + 1; i < M; i++) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}

					// 4번 타입 카메라 좌측 감시 또는 해제
					for (int i = CCTV[CCTVNumber].y - 1; i >= 0; i--) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
					// 4번 타입 카메라 아래 감시 또는 해제
					for (int i = CCTV[CCTVNumber].x + 1; i < N; i++) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					break;
				case 2: // 4번 타입 카메라 우측 감시 또는 해제
					for (int i = CCTV[CCTVNumber].y + 1; i < M; i++) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}

					// 4번 타입 카메라 위 감시 또는 해제
					for (int i = CCTV[CCTVNumber].x - 1; i >= 0; i--) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}

					// 4번 타입 카메라 아래 감시 또는 해제
					for (int i = CCTV[CCTVNumber].x + 1; i < N; i++) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					break;
				case 3: // 4번 타입 카메라 우측 감시 또는 해제
					for (int i = CCTV[CCTVNumber].y + 1; i < M; i++) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}

					// 4번 타입 카메라 위 감시 또는 해제
					for (int i = CCTV[CCTVNumber].x - 1; i >= 0; i--) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}

					// 4번 타입 카메라 좌측 감시 또는 해제
					for (int i = CCTV[CCTVNumber].y - 1; i >= 0; i--) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
				break;
			}
			break;

		case 5:
			switch (dir){
				case 0: // 5번 타입 카메라 우측 감시 또는 해제
					for (int i = CCTV[CCTVNumber].y + 1; i < M; i++) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}

					// 5번 타입 카메라 위 감시 또는 해제
					for (int i = CCTV[CCTVNumber].x - 1; i >= 0; i--) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}

					// 5번 타입 카메라 좌측 감시 또는 해제
					for (int i = CCTV[CCTVNumber].y - 1; i >= 0; i--) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
					// 5번 타입 카메라 아래 감시 또는 해제
					for (int i = CCTV[CCTVNumber].x + 1; i < N; i++) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					break;
				case 1: 
					break;
				case 2: 
					break;
				case 3: 
					break;
			}
			break;

			break;
	}
}

// CCTV가 볼 수 있는 모든 경우의 수를 확인합니다.
void DFS(int cctvNumber)
{
	// 만약 CCTV의 최대 개수를 넘거나 다음 CCTV가 없다면 빈 공간을 카운트 합니다.
	if (cctvNumber == 8 || CCTV[cctvNumber].type == -1) {		
		int temp = 0;
		// 사각지대를 카운트 합니다.
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[j][i] == 0){
					temp++;
				}
			}
		}

		if (temp < MinBlindSpot) {
			MinBlindSpot = temp;
		}
		return;
	}

	// 모든 경우의 수를 확인
	for (int i = 0; i < 4; i++) {
		switch (i)
		{
			case 0:
				MarkingMap(i, cctvNumber, 1);
				DFS(cctvNumber + 1);
				MarkingMap(i, cctvNumber, -1);
				break;

			case 1:
				MarkingMap(i, cctvNumber, 1);
				DFS(cctvNumber + 1);
				MarkingMap(i, cctvNumber, -1);
				break;

			case 2:
				MarkingMap(i, cctvNumber, 1);
				DFS(cctvNumber + 1);
				MarkingMap(i, cctvNumber, -1);
				break;
			case 3:
				MarkingMap(i, cctvNumber, 1);
				DFS(cctvNumber + 1);
				MarkingMap(i, cctvNumber, -1);
				break;
		}
	}
}

int main()
{
	Initialization();
	ReceiveInput();
	DFS(0);
	cout << MinBlindSpot;
	// 디버그용
	if (debugBool) DebugPrint();
	return 0;
}