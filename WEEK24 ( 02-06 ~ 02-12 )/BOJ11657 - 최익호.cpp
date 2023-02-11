#include <iostream>
#include <vector>

using namespace std;

constexpr long long int INF = INT64_MAX;

constexpr int MAXN = 501;

long long int disArr[MAXN];

bool check = false; // 음의 순환이 있는지 확인

// N : 도시의 개수, M : 버스 노선의 개수
// A : 시작 도시, B : 도착 도시, C : 걸리는 시간
int N, M, A, B, C;

vector<pair<int, int>> graph[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		// 단방향
		graph[A].push_back(make_pair(B, C));
	}

	// 배열 초기화
	fill(disArr, disArr + MAXN, INF);

	disArr[1] = 0;


	for (int k = 1; k <= N; k++) {// (모든 정점의 수 - 1) 번 확인한다.
		// 모든 노선을 확인한다.
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < graph[i].size(); j++) {

				int u = i; // 시작점
				int v = graph[i][j].first; // 도착점
				int weight = graph[i][j].second; // 가중치

				// 만약 임시 배열이 무한대가 아니고 &&
				// 시작 임시 배열의 가중치가 도착지의 가중치보다 작다면
				if (disArr[u] != INF && disArr[u] + weight < disArr[v]) {

					disArr[v] = disArr[u] + weight; // 임시배열을 업데이트 해준다.

					// K가 N-1일때 모든 정점을 확인한 후
					// K가 N일때 업데이트가 있다면 음의 순환이 있다는 이야기
					if (k == N) { 
						cout << "-1";
						return 0;
					}
				}
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (disArr[i] == INF) cout << "-1" << "\n";
		else cout << disArr[i] << "\n";
	}

	return 0;
}