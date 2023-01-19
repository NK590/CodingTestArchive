#include <iostream>
#include<memory.h> 
#include<stdio.h>
using namespace std;


int dp[1000000 + 1];
int dp2[1000000 + 1];
int N;
/*
N = 1 : 1
N = 2 : 00 11
N = 3 : 001 100 111
N = 4 : 0000 0011 1001 1100 1111
N = 5 : 10000 10011 11001 11100 11111 00001 00111 00100
dp[i] = dp[i-2] + dp[i-1];
*/

// ���Ҿ� ��� �ӵ� 4ms
void Solution()
{
	dp[0] = 1;
	dp[1] = 1;

	if (N == 0)
	{
		cout << "0" << endl;
		return;
	}
	for (int i = 2; i <= N; i++)
	{
		// �����⸦ ���ϸ� ������ �����ϸ� 45���� �� ������ �ϴٰ� 46������ ������ �����Ե˴ϴ�.
		dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
	}

	cout << dp[N] << endl;
}

int TopDown(int n)
{
	if (n == 0) return 1;
	if (n == 1) return 1;
	// �̹� ���� ����� ���� �ִٸ� �� ���� �ٷ� ����
	if (dp2[n] != -1) return dp2[n];
	// �ƴ϶�� ����ؼ� dp ����Ʈ�� �־� ����
	dp2[n] = (TopDown(n - 2) + TopDown(n - 1)) % 15746;
	return dp2[n];
}
// ž�ٿ��� �ӵ� 20ms
void Solution2()
{
	memset(dp2, -1, sizeof(dp2));
	if (N == 0)
		cout << 0 << endl;
	else
		cout << TopDown(N) << endl;
}


void Input()
{
	cin >> N;
}

int main()
{
	Input();
	//Solution();
	Solution2();

	return 0;
}