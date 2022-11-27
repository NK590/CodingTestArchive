#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <set>

using namespace std;

string S;
int K, M;
vector<int> Answer;

int Calcul(string s)
{
	int Sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		Sum *= 10;
		Sum += (s[i] - '0');
	}
	return Sum;
}

void BFS(string S) 
{
    queue<string> Q;
    Q.push(S);
    // 바꾼 횟수
    int cnt = 0;
    // 찾은 수 중 최대
    int ans = 0;

    while (!Q.empty() && cnt < K) {
        int Qs = Q.size();
        // 똑같은 수 바꾸기 반복 방지 (메모리 초과 방지)
        set<string> Visit;

        // cnt=i 일때 i번 바뀐수들이 Q에 저장되어 있다.
        // 모든 i번 바뀐 수들을 한번씩 더 바꿔본다.
        for (int q = 0; q < Qs; q++) {
            string now = Q.front();
            Q.pop();
            // 숫자 바꿔보기
            for (int i = 0; i < M - 1; i++) {
                for (int j = i + 1; j < M; j++) {
                    // 0 으로 숫자가 시작하면 안된다.
                    if (i == 0 && now[j] == '0') continue;

                    swap(now[i], now[j]);
                    if (!Visit.count(now)) {
                        // K번 바꾼경우 최대 수 찾기
                        if (cnt == K - 1)
                            ans = max(ans, Calcul(now));

                        Q.push(now);
                        Visit.insert(now);
                    }
                    swap(now[i], now[j]);
                }
            }
        }
        cnt++;
    }
    if (cnt != K) cout << -1 << endl;
    else cout << ans << endl;
}

int main()
{
    cin >> S >> K;
    M = S.length();
    // 주어진 수가 1자리 수일때 or 2자리이고 뒷자리 0 일때
    if (M == 1 || (M == 2 && Calcul(S) % 10 == 0))
        cout << "-1" << endl;
    else
        BFS(S);

    return 0;
}