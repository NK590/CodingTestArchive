#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

// 보석의 개수 N, 가방의 개수 K
int N, K;

// 결과 값의 범위가 int의 최대 범위를 넘어갈 수 있음
long long result = 0;

//<보석의 가치, 보석의 무게, 내림차순 정렬>
multimap<int, int, greater<int>> jewelryMultimap;

// <가방의 무게 , 사용 체크>
// 사용 체크는 사용을 안하지만 멀티맵 형식때문에 사용
multiset<int> bagMultiset;
//허용 무게가 낮은 순서대로 정렬된 가방

// 반복자 선언
multiset<int>::iterator it;


//  처음 초기화 함수
void Initializaion()
{
	cin >> N >> K;

	int tempW = 0;
	int tempV = 0;
	int temp = 0;

	// 보석의 개수에 따른 무게와 가치
	while (temp < N)
	{
		cin >> tempW >> tempV;
		jewelryMultimap.insert({ tempV, tempW });
		temp++;
	}
	temp = 0;

	// 가방 개수에 따른 허용 무게 데이터 입력
	while (temp < K)
	{
		cin >> tempW;
		bagMultiset.insert(tempW);
		temp++;
	}
	// 가방을 오름차순으로 정렬
}

void AlgorithmOfGreed()
{
	// 가치가 높은 순서대로 정렬된 보석들을 한번씩 순회한다.
	for (auto& elem : jewelryMultimap)
	{
	    // 허용 무게가 낮은 순으로 정렬된 가방들
		// 가방중에서 보석의 무게 이상의 값중 가장 가까운 값을 찾음
		for (it = bagMultiset.lower_bound(elem.second);it != bagMultiset.end(); it++)
		{
			//해당 가방을 찾으면 결과값에 가치르 더하고
			result += elem.first;
			// 해당 가방을 지움
			// bool 체크로 하려고 했으나 시간초과뜸
			bagMultiset.erase(it);
			break;
		}
	}
}

int main()
{
	// 초기화
	Initializaion();
	// 그리드 알고리즘
	AlgorithmOfGreed();
	cout << result;
	return 0;
}