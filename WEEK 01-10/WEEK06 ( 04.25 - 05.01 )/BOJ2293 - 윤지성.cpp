#include <iostream>
#include <vector>
using namespace std;

int d[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k, tmp;
	vector<int> coin;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		coin.push_back(tmp);
	}
	d[0] = 1;

	for (int i = 0; i < coin.size(); i++) {
		for (int j = coin[i]; j <= k; j++) {
			d[j] += d[j - coin[i]];
		}
	}

	cout << d[k];

	return 0;
}



