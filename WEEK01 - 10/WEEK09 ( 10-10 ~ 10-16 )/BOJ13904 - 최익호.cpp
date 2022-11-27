#include <iostream>
#include <queue>

using namespace std;

// 과제의 마감일을 기준으로 내림차순으로 정렬
priority_queue<pair<int, int>> PriorityQueue_DeadLine_Value;

// 과제의 점수를 기준으로 내림차순 정렬
priority_queue<int> PriorityQueue_Value;

int N, temp, temp2, taskDeadlineMax, result;
pair<int, int> myPair;

// 입력 초기화를 받는 부분
void Initailization()
{
	cin >> N;
	while (N > 0)
	{
		cin >> temp >> temp2;

		PriorityQueue_DeadLine_Value.push(make_pair(temp, temp2));

		// 과제 중에서 가장 높은 마감일 값을 찾는다.
		if (taskDeadlineMax < temp){ taskDeadlineMax = temp; }

		N--;
	}
}

void Recursive(int cuurentDay)
{
	// 만약 기준 날이 0 이면 리턴해서 결과 출력
	if (cuurentDay == 0){ return; }

	// 마감일 기준으로 정렬된 과제들 중에서 
	// 기준날과 같은 과제의 점수들만 다른 우선 큐에 담아둔다(점수 내림차순)
	while (!PriorityQueue_DeadLine_Value.empty())
	{
		myPair = PriorityQueue_DeadLine_Value.top();
		if (cuurentDay == myPair.first)
		{
			PriorityQueue_Value.push(myPair.second);
			PriorityQueue_DeadLine_Value.pop();
			continue;
		}
		break;
	}

	// 점수를 담아둔 큐에서 1개만 꺼내서 결과에 더해준다.
	if(!PriorityQueue_Value.empty())
	{
		result += PriorityQueue_Value.top();
		PriorityQueue_Value.pop();
	}

	// 기준날이 0 이 될때까지 재귀를 사용
	Recursive(cuurentDay - 1);
}

int main()
{

	Initailization();
	// 재귀 시작
	Recursive(taskDeadlineMax);
	cout << result;
	return 0;
}