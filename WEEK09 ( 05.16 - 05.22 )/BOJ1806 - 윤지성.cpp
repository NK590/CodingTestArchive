#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(100001);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, s, st = 0, end = 0, len = 200000, sum;
	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	sum = v[0];

	while (st <= end && end < n) {
		if (sum < s) //부분합이 s보다 작으면 v[++end] 더함
			sum += v[++end];		
		else { //부분합이 s 이상이면, 더 작은 길이값인지 검사하고, v[st] 빼고 st 증가
			len = min(len, end - st + 1);
			sum -= v[st++];
		}
	}
	
	cout << (len == 200000 ? 0 : len);

	return 0;
}
