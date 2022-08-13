#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*2023*/
int isPrime(int a, int b) {
	int k = 10 * a + b;
	for (int i = 2; i * i <= k; i++) {
		if (k % i == 0)
			return 0;
	}
	return k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int digit = pow(10, n - 1);

	for (int i = (n == 1 ? 2 * digit : 2 * digit + 1); i < 8 * digit; (n == 1 ? i++ : i += 2)) {
		if ((i / digit == 4 || i / digit == 6)) {
			if (n != 1)
				i += digit - 2;
			continue;
		}
		int a = i / digit, b, ten = 10;

		for (int j = 0; j < n - 1; j++) {
			b = (i / (digit / ten)) % 10;
			a = isPrime(a, b);
			if (!a)
				break;

			ten *= 10;
		}

		if (a)
			cout << i << "\n";
	}

	return 0;
}



