#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*2133*/
int d[31];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	d[0] = 1; //�ƹ��͵� �ȱ׸��� ��쵵 1�� ���
	d[2] = 3; // 2�϶� �׸��°�� 3����

	for (int i = 4; i <= n; i += 2) {
		d[i] = d[i - 2] * 3; //2ĭ������ �׸��� ���
		for (int j = i - 4; j >= 0; j -= 2) {
			d[i] += d[j] * 2; //4ĭ���� 2ĭ�� �ö����� Ư���� ��� 2������ �����Ƿ� �̰� ������
		}
	}
	cout << d[n];

	return 0;
}



