#include <iostream>
#include <set>
#include <queue>

using namespace std;

//우선 순위 Q를 사용하여 입력값을 정렬해준다.
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myQueue;

int result = 1;

// 강의들을 저장해 놓음
pair<int, int> mypair;

// 멀티맵을 사용하기 위한 준비
multiset<int> mymultiset;
multiset<int>::iterator iter;

// 입력값 초기화 함수
void Initialization()
{
	int N = 0;
	int S = 0;
	int T = 0;
	cin >> N;
	while (N > 0)
	{
		cin >> S >> T;
		myQueue.push(make_pair(S, T));
		N--;
	}
}

int main()
{
	// 입력값을 받아줍니다.
	Initialization();
	mypair = myQueue.top();
	myQueue.pop();
	mymultiset.insert(mypair.second);

	while (!myQueue.empty())
	{
		mypair = myQueue.top();
		myQueue.pop();
	 
		if (mypair.first < *mymultiset.begin())
		{
			mymultiset.insert(mypair.second);
			result++;
			continue;
		}

		iter = mymultiset.lower_bound(mypair.first);

		// 값이 같을 때도 같이 set에서 제거하고 페어를 추가해준다.
		if (*iter == mypair.first)
		{
			mymultiset.erase(iter);
		}
		else
		{
			mymultiset.erase(--iter);
		}
		
		mymultiset.insert(mypair.second);
	}
	cout << result;
	return 0;
}