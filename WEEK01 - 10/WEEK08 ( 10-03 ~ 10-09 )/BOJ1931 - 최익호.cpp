#include <iostream>
#include <queue>

using namespace std;

// 우선 큐로 정렬 강의가 끝나는 시간을 오름차순으로 정렬
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myQueue;

int result = 0;
int startLecture = 0;
int endLecture = 0;
int N = 0;

// 조건 초기화
void Initializtion()
{
	cin >> N;
	while (N > 0)
	{
		cin >> startLecture >> endLecture;
		myQueue.push(make_pair(endLecture, startLecture));
		N--;
	}
}

int main()
{
	Initializtion();

	// 현재 진행중인 강의가 끝나는 시간으로 생각
	int curEndLecture = 0;

	// 끝나는 시간이 가장 빠른 강의를 가져옴
	curEndLecture = myQueue.top().first;
	myQueue.pop();
	result++;

	// 주어진 강의를 모두 확인할때까지 반복
	while (!myQueue.empty())
	{
		endLecture = myQueue.top().first;
		startLecture = myQueue.top().second;
		myQueue.pop();

		// 끝나는 시간이 빠른 강의들의 시작 시간을 확인 
		// 강의의 시작시간이 끝나는 시간과 같거나 늦으면
		// 현재 진행중인 강의의 인덱스를 바꾸어줌
		// (강의를 진행한다는 의미)
		if (startLecture >= curEndLecture)
		{
			curEndLecture = endLecture;
			result++;
		}
	}

	cout << result;
	return 0;
}
