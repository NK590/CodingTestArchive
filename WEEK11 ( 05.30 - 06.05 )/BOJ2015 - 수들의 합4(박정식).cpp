#include <iostream>
#include <map>

using namespace std;

int psum[200001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	map<int, long long> m;
	long long ans = 0;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		// 누적합 구성
		psum[i] = psum[i - 1] + num;

		// 1. i까지의 누적합이 k인 경우
		if (psum[i] == k)
		{
			ans++;
		}

		// 2. psum[j]에 현재 psum[i] - k 를해서 나온적이 있다면 그값을 더함
		// psum[i] - psum[j] == k // 식 이용
		ans += m[psum[i] - k];		

		// 맵에 psum[i]를 등록해두어 psum[j] 역할하게 하기
		m[psum[i]]++;
		
	}

	cout << ans << endl;

	return 0;
}