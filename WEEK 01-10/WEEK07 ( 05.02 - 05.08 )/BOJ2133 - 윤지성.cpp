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

	d[0] = 1; //아무것도 안그리는 경우도 1로 취급
	d[2] = 3; // 2일때 그리는경우 3가지

	for (int i = 4; i <= n; i += 2) {
		d[i] = d[i - 2] * 3; //2칸전까지 그리는 경우
		for (int j = i - 4; j >= 0; j -= 2) {
			d[i] += d[j] * 2; //4칸부터 2칸씩 늘때마다 특수한 경우 2가지씩 나오므로 이걸 더해줌
		}
	}
	cout << d[n];

	return 0;
}



