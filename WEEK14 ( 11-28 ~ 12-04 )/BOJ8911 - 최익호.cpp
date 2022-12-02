#include <iostream>
#include <list>
#include <set>

using namespace std;

int T;

string tempString;

list<string> testCase;

int directionTurtle[4][2] = {
	{0, 1 },
	{1, 0 },
	{0, -1},
	{-1, 0}
};

// 초기화
void Initializtion()
{
	cin >> T;
	while (T > 0)
	{
		cin >> tempString;
		testCase.push_back(tempString);
		T--;
	}

}

// 거북이가 지나간 영역을 포함하는 가장 작은 직사각형 계산 함수 
int SizeCalculation(string testcase)
{
	int curX = 0;
	int curY = 0;
	int conditionTurtle = 0;
	set<int> xSet;
	set<int> ySet;
	xSet.insert(curX);
	ySet.insert(curY);

	// 명령어를 처리하는 부분
	for (int i = 0; i < testcase.size(); i++)
	{
		switch (testcase[i])
		{
			case 'F': // 전진
				curX += directionTurtle[conditionTurtle][0];
				curY += directionTurtle[conditionTurtle][1];
				break;

			case 'B': // 후진
				curX -= directionTurtle[conditionTurtle][0];
				curY -= directionTurtle[conditionTurtle][1];
				break;

			case 'L': // 왼쪽으로 90도 회전
				conditionTurtle--;
				if (conditionTurtle <= -1) {
					conditionTurtle = 3; }
				break;

			case 'R': // 우측으로 90도 회전
				conditionTurtle++;
				if (conditionTurtle >= 4) {
					conditionTurtle = 0; }
				break;

			default:
				cout << "이거 나오면 큰일남";
				break;
		}

		xSet.insert(curX);
		ySet.insert(curY);
	}

	// Set<int>를 이용하여 x,y의 가장 낮은 값과 높은값을 계산하여 직사각형 가로 세로를 구한다.
	int width = *xSet.begin() - *--xSet.end();
	int height = *ySet.begin() - *--ySet.end();

	return abs(width * height);
}


int main()
{
	Initializtion();
	 
	//테스트 케이스 만큼 반복
	for (auto iter = testCase.begin(); iter != testCase.end(); iter++)
	{
		cout << SizeCalculation(*iter) << "\n";
	}

	return 0;
}