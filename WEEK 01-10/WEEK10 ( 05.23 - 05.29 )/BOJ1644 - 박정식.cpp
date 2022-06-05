#define MAX 4000001

#include <iostream>
#include <vector>

using namespace std;
int numbers[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int result = 0;
	vector<int> primeNumbers;

	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		numbers[i] = i;
	}

	// 에라토스테네스의 체 를이용하여 소수 구하기.
	for (int i = 2; i*i <= n; i++)
	{
		if (numbers[i] == 0) continue;
		for (int j = i * i; j <= n; j += i)
		{
			numbers[j] = 0;
		}
	}
	// 구한 소수들 vector에 저장
	for (int i = 2; i <= n; i++)
	{
		if (numbers[i] != 0)
		{
			primeNumbers.push_back(i);
		}
	}

	int primeNumberSize = primeNumbers.size();	
	for (int i = 0; i < primeNumberSize; i++)
	{
		// 소수 배열의 첫번째부터 소수의 갯수번째까지 다더해본다
		int sum = 0; 
		for (int j = i; j < primeNumberSize; j++)
		{	
			// 소수의 연속된합만을 인정하기 때문에 배열의 순서대로 더했을때 n이되는경우만 카운트 증가
			sum += primeNumbers[j];
			if (sum == n)
			{
				result++;
			}
			else if (sum > n)
			{
				break;
			}
		}
	}

	cout << result;
}