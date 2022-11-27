#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	// <���� Ǯ��> �켱���� ť
	// �׻� ī�� ���� �ּҰ� �Ǵ� ī�� �������� ��ġ�� �˴ϴ�.
	//	�ּ� ���� ����ؼ� �Է¹��� �����͸� ��� push �մϴ�.
	// ����� 1�� �� ������ ������ �ݺ��մϴ�.
	// 1. �ּ� ������ �� ���� ������.
	// 2. �� ���� ���� ����� sum�� �߰��Ѵ�.
	// 3. �� ���� ���� ����� �ּ� ���� push �Ѵ�.


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