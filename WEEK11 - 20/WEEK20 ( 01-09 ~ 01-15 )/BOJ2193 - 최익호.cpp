#include <iostream>

using namespace std;

long long int arr[91]; // N은 최대 90

int main()
{
	// Tabulation: Bottom Up 방식

	long long int N = 0;

	cin >> N;

	arr[0] = 0, arr[1] = 1;

	for (int  i = 2; i <= N; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cout << arr[N];

	return 0;
}