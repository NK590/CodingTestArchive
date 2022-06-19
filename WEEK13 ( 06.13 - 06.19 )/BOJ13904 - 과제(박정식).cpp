#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

// ���� ������ �������� ����
bool compare(pair <int, int> pair1, pair <int, int> pair2)
{
	return pair1.second > pair2.second;
}

int main()
{
	int n;
	int lastDay = 0;
	// �Ҽ��ִ� ���� ����Ʈ ���� ����
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
	// ������ ������ �۾� ����Ʈ ���� ����	
	vector<int> workList(lastDay+1, 0);
	for (int i = 0; i < n; i++)
	{
		// ������ ���� ������� �����Ͽ� �۾� ó��
		if (workList[assignmentList[i].first] == 0)
		{
			workList[assignmentList[i].first] = assignmentList[i].second;
		}
		// ���� �̹� �ش� �����Ͽ� �۾��� �����Ǿ� �ִٸ� �Ϸ羿 �������� ���� ����
		else
		{
			// 0�Ͽ� �۾��� ���ϴ� ������ ó���ϹǷ� day-1 ������ ó��
			for (int j = assignmentList[i].first; j > 0; j--)
			{
				// �Ϸ羿 �������� �۾��� ���� ���� ã��
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
