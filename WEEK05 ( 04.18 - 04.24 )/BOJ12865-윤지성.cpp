#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*12865*/
int n, k, maxi;
vector<int> item[101];
int d[101][100001];
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		item[i].push_back(w);
		item[i].push_back(v);
	}

	for (int i = 0; i < n; i++) {
		if (!i) {
			d[i][item[i][0]] = item[i][1];
			if(item[i][0] <= k)
				maxi = item[i][1];
			continue;
		}
		for (int j = 1; j <= k; j++) {
			if (j - item[i][0] >= 0)
				d[i][j] = max(d[i - 1][j], d[i - 1][j - item[i][0]] + item[i][1]);
			else
				d[i][j] = d[i - 1][j];

			if (d[i][j] > maxi)
				maxi = d[i][j];
		}
	}

	cout << maxi;

	return 0;
}

