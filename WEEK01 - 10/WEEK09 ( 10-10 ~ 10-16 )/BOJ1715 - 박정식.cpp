#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	// <문제 풀이> 우선순위 큐
	// 항상 카드 수가 최소가 되는 카드 묶음끼리 뭉치면 됩니다.
	//	최소 힙을 사용해서 입력받은 데이터를 모두 push 합니다.
	// 사이즈가 1이 될 때까지 다음을 반복합니다.
	// 1. 최소 힙에서 두 개를 꺼낸다.
	// 2. 두 개를 더한 결과를 sum에 추가한다.
	// 3. 두 개를 더한 결과를 최소 힙에 push 한다.


	priority_queue<int, vector<int>, greater<int>> pq;
	int cnt;
	int result = 0;

	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		int number;
		cin >> number;
		pq.push(number);
	}

	while (pq.size() != 1)
	{
		int num1, num2;
		num1 = pq.top();
		pq.pop();
		num2 = pq.top();
		pq.pop();
		result = result + num1 + num2;
		pq.push(num1 + num2);
	}

	cout << result << endl;

	return 0;
}