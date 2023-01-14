#include <iostream>
#include <string>
using namespace std;

string S;
int N;
string A[100];
int dp[101];

// dp[pos] = 문자열의 pos번째 글자부터 마지막 글자까지의 string을 주어진 단어들로 만들 수 있는지를 나타냄.
void Solution()
{
	dp[S.length()] = 1;

	for (int pos = S.length() - 1; pos >= 0; pos--)
	{
		for (int j = 0; j <= N; j++)
		{
			// 해당 위치(Pos)에 일치하는 단어가 있으면서
			// 해당하는 단어의 길이만큼 pos를 더했을때 dp 배열에 만들 수 있다고 저장이 되어있는지 체크
			// pos  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14
			//	S	s  o  f  t  w  a  r  e  c  o  n  t  e  s  t
			// 예시
			// pos가 8일 때
			// contest를 S.find("contest", 8) 찾을 수 있으면서 dp[8+7] == 1이므로 단어를 완성할 수 있다는 것을 검증 완료 dp[8] = 1로 체크
			// pos가 0일 때
			// software를 S.find("software", 0) 찾을 수 있으면서 dp[0+8] == 1이므로 단어를 완성할 수 있다는 것을 검증 완료 dp[0] = 1로 체크

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