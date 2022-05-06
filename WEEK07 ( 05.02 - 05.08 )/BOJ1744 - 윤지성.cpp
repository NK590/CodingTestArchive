#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*1744*/
int n, tmp, minu, sum;
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);

		if (tmp <= 0)
			minu++; //0 이하인 수 갯수 세기
	}

	sort(v.begin(), v.end()); //오름차순 정렬


	for (int i = 0; i < v.size(); i += 2) {
		if (i + 1 == minu || (v.size() - minu) % 2 == 1 && i == minu) { //0 이하인수 or 양수가 홀수일 때 처리
			sum += v[i];
			i--;
		}
		else
			sum += (v[i] * v[i + 1] > v[i] + v[i + 1] ? v[i] * v[i + 1] : v[i] + v[i + 1]); //묶기 vs 안묶기 비교해 더하기
	}

	cout << sum;

	return 0;
}



