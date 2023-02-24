#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

constexpr int MAX = 101;

int T, N;

vector<pair<int, int>> graph[MAX];

bool isVisted[MAX], check;

pair<int, int> Start, Temp;

void DFSSearch(int x, int y)
{
	// 도착이 가능하다면 마킹하고 리턴
	if (x == graph[N][0].first && y == graph[N][0].second) {
		check = true;
	}

	for (int i = 0; i <= N; i++) {

		// 방문 했다면 넘어간다. 
		if (isVisted[i] == true) continue;
		// 거리의 절대값으로 도착이 가능한지 불가능한지 체크
		if (abs(graph[i][0].first - x) + abs(graph[i][0].second - y) <= 1000) {

			isVisted[i] = true; // 방문 체크

			DFSSearch(graph[i][0].first, graph[i][0].second);
			// isVisted[i] = false; // 방문 체크를 해제하면 시간초과
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {

		// 조건 초기화
		fill(isVisted, isVisted + MAX, false);

		for (int i = 0; i < MAX; i++) graph[i].clear();

		check = false; // 가능한지 불가능한지 탐색

		// 시작 위치를 입력
		cin >> N >> Start.first >> Start.second;	

		for (int i = 0; i <= N; i++) {

			// 편의점의 위치를 입력받는다.
			cin >> Temp.first >> Temp.second;
			// 마지막은 도착 위치를 입력받는다.
			graph[i].push_back(make_pair(Temp.first, Temp.second));

		}

		DFSSearch(Start.first, Start.second);
		
		if (check) cout << "happy\n";
		else cout << "sad\n";

	}

	return 0;
}