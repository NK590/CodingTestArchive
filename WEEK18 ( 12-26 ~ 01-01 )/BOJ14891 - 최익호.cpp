#include <iostream>
#include <list>
#include <cmath>

using namespace std;

// 톱니바퀴의 회전 횟수
int N, tempOne, tempTwo;

list<pair<int, int>> rotationList;
list<pair<int, int>>::iterator iter;

// 톱니 바퀴의 톱니
string cogWheel[4];

// 회전할 톱니체크에 필요
bool check[3];

bool debug = false;

// 결과
int score = 0;

// 디버그용 함수
void DebugPrint()
{
	cout << "\n" << "톱니바퀴의 상태\n";
	for (int i = 0; i < 4; i++) {
		cout << cogWheel[i] << "\n";
	}
}

// 문제의 입력을 받는 함수
void GetInput()
{
	for (int i = 0; i < 4; i++) {
		cin >> cogWheel[i];
	}
	cin >> N;

	// 톱니바퀴의 회전수 만큼 입력을 받습니다.
	while (N > 0) {
		cin >> tempOne >> tempTwo;
		rotationList.push_back(make_pair(tempOne, tempTwo));
		N--;
	}
}

// 톱니를 회전하는 함수
void CogwheelRotation(int number, int dir)
{
	string tempString;

	// 톱니를 시계 방향으로 회전
	if (dir == 1) {
		tempString.push_back(cogWheel[number - 1][7]);
		for (int i = 0; i < 7; i++) {
			tempString.push_back(cogWheel[number - 1][i]);
		}
		if (debug) { cout << number << "번 톱니 " << "시계 방향 회전 : " << cogWheel[number - 1] << " -> "; }
		cogWheel[number - 1] = tempString;
		if (debug) { cout << tempString << "\n"; }
	}
	else { 	// 톱니를 반시계 방향으로 회전
		for (int i = 1; i < 8; i++) {
			tempString.push_back(cogWheel[number - 1][i]);
		}

		tempString.push_back(cogWheel[number - 1][0]);
		if (debug) { cout << number << "번 톱니 " << "반시계 방향 회전: " << cogWheel[number - 1] << " -> "; }
		cogWheel[number - 1] = tempString;
		if (debug) { cout << tempString << "\n"; }
	}

}

// 회전할 톱니를 체크
void RotationCheck(int number, int dir)
{

	for (int i = 0; i < 3; i++) {
		cogWheel[i + 1][6] != cogWheel[i][2] ? check[i] = true : check[i] = false;
	}
	if (debug) { cout << "\n" << "문제의 톱니바퀴 회전" << "\n"; }

	CogwheelRotation(number, dir);

	if (debug) { DebugPrint(); }
	if (debug) { cout << "\n" << "상호작용 시작" << "\n"; }

	switch (number)
	{
		case 1: // 2번부터 4번
			for (int i = 0; i < 3; i++) {
				if (check[i]) { CogwheelRotation(i + 2, dir * pow(-1, i + 1)); }
				else { break; }
			}
			break;

		case 2: //3번부터 4번
			for (int i = 1; i < 3; i++) {
				if (check[i]) {
					CogwheelRotation(i + 2, dir * pow(-1, i)); }
				else { break; }
			}

			// 1번
			if (check[0]) { CogwheelRotation(1, -dir); }
			break;

		case 3: // 2번부터 1번
			for (int i = 1; i >= 0; i--) {
				if (check[i]) {
					CogwheelRotation(i + 1, dir * pow(-1, i));
				}
				else { break; }
			}

			// 4번
			if (check[2]) { CogwheelRotation(4, -dir); }
			break;

		case 4: // 3번부터 1번
			for (int i = 2; i >= 0; i--) {
				if (check[i]) {
					CogwheelRotation(i + 1, dir * pow(-1, i + 1));
				}
				else { break; }
			}
			break;
	}
}

// 점수를 계산하는 함수
void ScoreCalculation()
{
	for (int i = 0; i < 4; i++) {
		if (cogWheel[i][0] == '1') { score += pow(2, i); }
	}
}

int main()
{
	GetInput();

	for (iter = rotationList.begin(); iter != rotationList.end(); iter++) {
		RotationCheck(iter->first, iter->second);
		if (debug) { 
			DebugPrint(); 
		}
	}

	// 점수 계산
	ScoreCalculation();

	if (debug) { 
		DebugPrint(); 
		cout << "\n답 : ";
	}

	cout << score;

	return 0;
}