#include <iostream>
#include <vector>

using namespace std;

int N, K;
int order[101]; //K : order
int tab[101]; //N : tab

int main()
{
	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> order[i];
	}

	int result = 0;

	for (int i = 0; i < K; i++) //순서대로 하나씩 시작
	{
		bool isUsed = false;

		for (int j = 0; j < N; j++) //현재 order에서 꽂아야하는 제품이 콘센트에 꽂혀있는지 확인
		{
			if (order[i] == tab[j])
			{
				isUsed = true;
				break;
			}
		}

		if (isUsed) continue; //꽂혀있으면 다음 제품으로 넘어감

		for (int j = 0; j < N; j++) //안꽂혀있는데 콘센트에 남은 자리가 있으면 꽂음
		{
			if (tab[j] == 0) //비어있는 콘센트중 제일 앞에 꽂음
			{
				tab[j] = order[i];
				isUsed = true;
				break;
			}
		}

		if (isUsed) continue; //방금 꽂았으니 넘어감

		//이미 탭에 다 꽂혀있어서 이전꺼와 교체하는 상황

		int swap = -1; //교체할 탭의 위치
		int temp = -1; //재사용 기간이 가장 먼 최댓값을 찾기위한 임시값

		for (int j = 0; j < N; j++) //탭에 꽂혀있는 제품을 하나하나 체크할거임
		{
			int term = 0;

			for (int l = i + 1; l < K && tab[j] != order[l]; l++) //지금 확인하는 탭의 제품이 다음 재사용 될때까지
			{
				term++;
			}

			if (term > temp)
			{
				swap = j;
				temp = term;
			}

		}

		result++;
		tab[swap] = order[i];
	}
	cout << result << "\n";
	return 0;
}