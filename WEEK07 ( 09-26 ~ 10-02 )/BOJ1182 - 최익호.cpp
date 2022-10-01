#include <iostream>

using namespace std;

int N, S, result;

// 자주 사용할 것 같아 매크로로 등록 
#define MAX 20

int numbers[MAX];

void SettingCondition()
{
	result = 0;

	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}
}

void DFS(int index, int total)
{
	if (index == N)
	{
		if (total == S)
		{
			result++;
			return;
		}
		//인덱스 마지막에 리턴
		return;
	}

	// 해당 인덱스의 원소를 사용할때 / 안할때
	DFS(index + 1, total + numbers[index]);
	DFS(index + 1, total);
}

int main()
{
	// 셋팅
	SettingCondition();
	DFS(0,0);
	
	// S = 0 이면 처음 시작 시 수열의 원소가 없지만 
	// total이 0 이므로 카운트가 하나 올라간다.
	if (S == 0) 
	{
		result--;
	}
	cout  << result;
	return 0;
}