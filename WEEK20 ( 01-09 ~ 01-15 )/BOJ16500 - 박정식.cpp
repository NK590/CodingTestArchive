#include <iostream>
#include <string>
using namespace std;

string S;
int N;
string A[100];
int dp[101];

// dp[pos] = ���ڿ��� pos��° ���ں��� ������ ���ڱ����� string�� �־��� �ܾ��� ���� �� �ִ����� ��Ÿ��.
void Solution()
{
	dp[S.length()] = 1;

	for (int pos = S.length() - 1; pos >= 0; pos--)
	{
		for (int j = 0; j <= N; j++)
		{
			// �ش� ��ġ(Pos)�� ��ġ�ϴ� �ܾ �����鼭
			// �ش��ϴ� �ܾ��� ���̸�ŭ pos�� �������� dp �迭�� ���� �� �ִٰ� ������ �Ǿ��ִ��� üũ
			// pos  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14
			//	S	s  o  f  t  w  a  r  e  c  o  n  t  e  s  t
			// ����
			// pos�� 8�� ��
			// contest�� S.find("contest", 8) ã�� �� �����鼭 dp[8+7] == 1�̹Ƿ� �ܾ �ϼ��� �� �ִٴ� ���� ���� �Ϸ� dp[8] = 1�� üũ
			// pos�� 0�� ��
			// software�� S.find("software", 0) ã�� �� �����鼭 dp[0+8] == 1�̹Ƿ� �ܾ �ϼ��� �� �ִٴ� ���� ���� �Ϸ� dp[0] = 1�� üũ

			if (S.find(A[j], pos) == pos && dp[pos + A[j].length()] == 1)
			{
				dp[pos] = 1;
				break;
			}
			else {
				dp[pos] = 0;
			}
		}
	}

	cout << dp[0];
}

void Input()
{
	cin >> S;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
}

int main() 
{
	Input();
	Solution();

	return 0;
}