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

	// �����佺�׳׽��� ü ���̿��Ͽ� �Ҽ� ���ϱ�.
	for (int i = 2; i*i <= n; i++)
	{
		if (numbers[i] == 0) continue;
		for (int j = i * i; j <= n; j += i)
		{
			numbers[j] = 0;
		}
	}
	// ���� �Ҽ��� vector�� ����
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
		// �Ҽ� �迭�� ù��°���� �Ҽ��� ������°���� �ٴ��غ���
		int sum = 0; 
		for (int j = i; j < primeNumberSize; j++)
		{	
			// �Ҽ��� ���ӵ��ո��� �����ϱ� ������ �迭�� ������� �������� n�̵Ǵ°�츸 ī��Ʈ ����
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