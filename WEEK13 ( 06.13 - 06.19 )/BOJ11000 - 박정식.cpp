#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;


int main()
{
	int n;

	cin >> n;

	vector<pair<int, int>> classList;

	for (int index = 0; index < n; index++)
	{
		int startTime, finishTime;

		cin >> startTime >> finishTime;
		// 종료시간을 기준으로 정렬하기 위해 pair에 첫번쨰요소를 종료시간으로 값 할당
		classList.push_back({ startTime , finishTime });
	}

	sort(classList.begin(), classList.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(classList[0].second);
	for (int index = 1; index < n; index++)
	{
		if (pq.top() <= classList[index].first)
		{
			pq.pop();
			pq.push(classList[index].second);
		}
		else
		{
			pq.push(classList[index].second);
		}
	}

	cout << pq.size() << endl;

	return 0;
}