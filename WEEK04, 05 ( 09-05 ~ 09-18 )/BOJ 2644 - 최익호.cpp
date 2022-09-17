#include <iostream>
#include <queue>

using namespace std;

#define Max 101 

int kinshipArr[Max][Max];
// 부모자식 관계를 표현 기본 0 ;

int checkArr[Max];

int inputPeopleNumber, targetX, targetY;
// 입력받을 사람의 수, 촌수를 계산할 x,y  // 결과

queue<int> myQ;


// 전체적으로 초기화 시켜주는 함수
void Initialization()
{
	// 관계의 수
	int degreeOfKinshipNumber;
	
	cin >> inputPeopleNumber >> targetX >> targetY >> degreeOfKinshipNumber;

	// 촌수 배열 초기화
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			kinshipArr[i][j] = 0;
			kinshipArr[j][i] = 0;

		}

		checkArr[i] = 0;
	}

	// 입력받은 관계의 수 만큼 반복 
	while (degreeOfKinshipNumber > 0)
	{
		int x, y;
		cin >> x >> y;

		// 촌수만 계산하면되므로 방향성은 의미없음 
		kinshipArr[x][y] = 1;
		kinshipArr[y][x] = 1;

		degreeOfKinshipNumber--;
	}
}


// BFS함수
void BFS(int targetX)
{
	myQ.push(targetX);

	// Q가 비어있을때까지 반복
	while (!myQ.empty())
	{
		int a = myQ.front();
		myQ.pop();

		// 사람수 만큼 반복
		for (int i = 1; i <= inputPeopleNumber; i++)
		{
			// 관계가 없거나 방문한 적이 있으면 넘어간다.
			if (kinshipArr[i][a] == 0 || checkArr[i] != 0) 
			{
				continue;
			} 
			
			myQ.push(i);
			checkArr[i] = checkArr[a] + 1; 
			// targetX와 모든 사람들의 촌수를 계산
		}
	}
}

int main()
{
	Initialization();
	BFS(targetX);
	
	int result;
	// targetY의 값을 가져와서 촌수가 있는지 없는지 판별
	if (checkArr[targetY] == 0)
	{
		result = -1;
	}
	else
	{
		result = checkArr[targetY];
	}

	cout << result;
	return 0;
}