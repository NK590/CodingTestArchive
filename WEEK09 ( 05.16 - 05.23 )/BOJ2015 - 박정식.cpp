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

	cin >> n >> k;

	for (int index = 1; index <= n; index++)
	{
		int num;
		cin >> num;
		psum[index] = psum[index - 1] + num;
	}

	long long ans = 0;
	for (int index = 1; index <= n; index++)
	{
		if (psum[index] == k)
		{
			ans++;
		}
		ans += m[psum[index] - k];
		m[psum[index]]++;
	}
	cout << ans << endl;

	return 0;
}