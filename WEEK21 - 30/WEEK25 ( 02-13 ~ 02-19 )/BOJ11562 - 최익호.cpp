#include <iostream>
#include <vector>
#include <list>

using namespace std;

constexpr int INF = INT32_MAX / 2;

constexpr int MAX = 251;

vector<pair<int, int>> graph[MAX];

list<pair<int, int>> myList;

int disArr[MAX][MAX];

// N : 도시의 수, M : 길의 수
int N, M, s, d, w, b, K, result;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	// 최단 거리 배열 disArr 배열을 INF 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			disArr[i][j] = INF;
		}
	}

	// 길의 정보를 입력
	for (int i = 0; i < M; i++) {

		// 출발 s, 도착 d, b 양/단 방향
		cin >> s >> d >> b;

		if (b == 0) { // 단방향
			graph[s].push_back(make_pair(d, 0));
			disArr[d][s] = 1; // (disArr[i][k] + disArr[k][j] vs INF)
		}
		else { // 양방향
			graph[s].push_back(make_pair(d, 0));
			graph[d].push_back(make_pair(s, 0));
		}

	}

	// 질문을 입력 받는다.
	cin >> K;

	pair<int, int> tempP;

	while (K--) {
		cin >> tempP.first >> tempP.second;
		myList.push_back(tempP);
	}

	for (int i = 1; i <= N; i++) { // 시작 정점
		for (int j = 0; j < graph[i].size(); j++) {

			int v = graph[i][j].first; // 도착점
			int weight = graph[i][j].second; // 가중치
			if (disArr[i][v] > weight) disArr[i][v] = weight;
		}
	}

	// 무지성 플로이드
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {

				if (i == j) disArr[i][j] = 0;
				else disArr[i][j] = min(disArr[i][j], disArr[i][k] + disArr[k][j]);

			}
		}
	}

	for (auto it = myList.begin(); it != myList.end(); it++) {
		cout << disArr[it->first][it->second] << "\n";		
	}

	return 0;
}