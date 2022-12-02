#include <iostream>

using namespace std;

// 문제의 예상 결과를 넣기
int predictedArr[4][6][3];

// 가능한 경기는 총 15경기
int gameArr1[15] = {0,0,0,0,0,1,1,1,1,2,2,2,3,3,4};
int gameArr2[15] = {1,2,3,4,5,2,3,4,5,3,4,5,4,5,5};

// Win Draw Lose 결과
int scoreWDL[6][3];

// 결과를 저장해서 마지막에 출력
int result[4];


void Initalization()
{
	//결과 초기화
	for (int i = 0; i < 4; i++)
	{
		result[i] = 0;
	}

	// 예상 스코어를 받습니다.
	for (int n = 0; n < 4; n++)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> predictedArr[n][i][j];
			}
		}
	}
}

void CheckScoreRecursive(int gameCnt)
{
	// 만약 모든 경기가 끝났다면
	if (gameCnt == 15)
	{
		//비교
		for (int n = 0; n < 4; n++) {

			bool check = true;

			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (predictedArr[n][i][j] != scoreWDL[i][j])
					{
						check = false;
						break;
					}
				}

				// 예측 결과가 가능하면 브레이크
				if (!check) break;
			}

			// 해당 결과가 가능하면 진입
			if (check) 
			{
				result[n] = 1;
			}
		}

		return;
	}

	// 기준은 Arr1
	// 승리했을 경우
	scoreWDL[gameArr1[gameCnt]][0]++;
	scoreWDL[gameArr2[gameCnt]][2]++;
	CheckScoreRecursive(gameCnt + 1);
	scoreWDL[gameArr1[gameCnt]][0]--;
	scoreWDL[gameArr2[gameCnt]][2]--;

	// 무승부일 경우
	scoreWDL[gameArr1[gameCnt]][1]++;
	scoreWDL[gameArr2[gameCnt]][1]++;
	CheckScoreRecursive(gameCnt + 1);
	scoreWDL[gameArr1[gameCnt]][1]--;
	scoreWDL[gameArr2[gameCnt]][1]--;

	// 패배의 경우
	scoreWDL[gameArr1[gameCnt]][2]++;
	scoreWDL[gameArr2[gameCnt]][0]++;
	CheckScoreRecursive(gameCnt + 1);
	scoreWDL[gameArr1[gameCnt]][2]--;
	scoreWDL[gameArr2[gameCnt]][0]--;

}

int main()
{
	Initalization();

	// DFS로 시작 
	CheckScoreRecursive(0);

	// 결과 출력
	for (int i = 0; i < 4; i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}