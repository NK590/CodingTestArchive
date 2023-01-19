#include <iostream>

using namespace std;

constexpr int MOD = 10007;
					
long long int arr[1001];

int main()
{
	// Tabulation: Bottom Up 방식

	long long int N = 0;

	cin >> N;

	arr[1] = 1, arr[2] = 2;

	for (int  i = 3; i <= N; i++) {
		arr[i] = ( arr[i - 1] % MOD + arr[i - 2] % MOD) % MOD;
	}

	cout << arr[N];

	return 0;
}
