#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

// 점수 순으로 내림차순 정렬
bool compare(pair <int, int> pair1, pair <int, int> pair2)
{
	return pair1.second > pair2.second;
}

int main()
{
	int n;
	int lastDay = 0;
	// 할수있는 과제 리스트 저장 벡터
	vector<pair<int, int>> assignmentList;
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int deadline, score;
		cin >> deadline >> score;
		assignmentList.push_back({ deadline, score });
		if (lastDay < deadline)
			lastDay = deadline;
	}

	sort(assignmentList.begin(), assignmentList.end(), compare);
	// 실질적 수행할 작업 리스트 저장 벡터	
	vector<int> workList(lastDay+1, 0);
	for (int i = 0; i < n; i++)
	{
		// 점수가 높은 순서대로 마감일에 작업 처리
		if (workList[assignmentList[i].first] == 0)
		{
			workList[assignmentList[i].first] = assignmentList[i].second;
		}
		// 만약 이미 해당 마감일에 작업이 배정되어 있다면 하루씩 내려가며 과제 수행
		else
		{
			// 0일엔 작업을 못하는 것으로 처리하므로 day-1 까지만 처리
			for (int j = assignmentList[i].first; j > 0; j--)
			{
				// 하루씩 내려가며 작업이 없는 날을 찾음
				if (workList[j] == 0)
				{
					workList[j] = assignmentList[i].second;
					break;
				}
			}
		}
	}
	int workListSize = workList.size();
	int result = 0;
	for (int index = 0; index < workListSize; index++)
	{
		result += workList[index];
	}
	cout << result << endl;
	return 0;
}
