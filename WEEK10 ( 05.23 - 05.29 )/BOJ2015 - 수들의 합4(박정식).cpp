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
		// ������ ����
		psum[i] = psum[i - 1] + num;

		// 1. i������ �������� k�� ���
		if (psum[i] == k)
		{
			ans++;
		}

		// 2. psum[j]�� ���� psum[i] - k ���ؼ� �������� �ִٸ� �װ��� ����
		// psum[i] - psum[j] == k // �� �̿�
		ans += m[psum[i] - k];		

		// �ʿ� psum[i]�� ����صξ� psum[j] �����ϰ� �ϱ�
		m[psum[i]]++;
		
	}

	cout << ans << endl;

	return 0;
}