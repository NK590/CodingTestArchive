#include <iostream>

using namespace std;

constexpr auto MAX = 500;

int map[MAX][MAX];

// N 세로, M 가로, B 인벤토리의 블럭 개수, area 맵의 넓이, MB 맵의 블럭들의 합
int N, M, B, Area, MB;

// 시간과 높이를 저장
pair<int, int> result;

bool debug = false;

// 문제의 입력을 받는 함수
void ReceiveInput()
{
	cin >> N >> M >> B;

	MB = 0;
	result.first = INT32_MAX;
	result.second = INT32_MAX;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			MB += map[i][j];
		}
	}

	if (debug) {
		cout << "\n----------------- 디버그 -----------------\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "N : " << N << " M : " << M << " B : " << B << " Area : " << Area << " MB : " << MB << "\n";
	}

	// 맵의 넓이를 계산
	Area = N * M;
}

// 시뮬레이션을 시작합니다.
void Simulation(int target)
{
	// 인벤토리 + 맵의 모든 블럭 >= 목표의 높이에 필요한 블럭의 개수
	if (B + MB < target * Area) { return; }
	int tempTime = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] < target) { // 목표의 높이가 현재 맵보다 높을 경우
				tempTime += (target - map[i][j]) * 1; // 높이만큼 시간을 더해줌
			}
			else if (map[i][j] > target) { // 목표의 높이가 현재 맵보다 낮을 경우
				tempTime += (target - map[i][j]) * -2; // 높이만큼 시간을 더해줌
			}

		}
	}

	// 만약 땅 고르기에 걸리는 시간이 더 적다면 
	if (result.first > tempTime) { 
		result.first = tempTime; 
		result.second = target;
		// 땅 고르기에 걸리는 시간이 같을때 높이가 더 높은 쪽으로 결과를 출력
		// 로직은 위에서부터 확인하기 때문에 따로 처리 X 
	} 
}


int main()
{
	ReceiveInput();

	int cnt = 256;
	while (cnt >= 0) { // 256 ~ 0 까지 목표를 시뮬레이션 합니다.
		Simulation(cnt);
		cnt--;
	}

	cout << result.first << " " << result.second;
	return 0;
}