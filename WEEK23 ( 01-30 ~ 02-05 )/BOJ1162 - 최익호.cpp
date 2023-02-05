#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

constexpr long long int INF = INT64_MAX;

long long int disArr[10001][21];

priority_queue<tuple<long long int, int, int>> myPQ;

vector<pair<int, int>> graph[50000];

int N, M, K, U, V, dist, cnt;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {

		cin >> U >> V >> dist;
        // 양방향 도로
		graph[U].push_back(make_pair(V, dist));

        graph[V].push_back(make_pair(U, dist));

	}

    // 다익스트라 배열 초기화
	for (int i = 1; i <= N; i++)
        for (int j = 0; j <= 20; j++)
            disArr[i][j] = INF;


	// 우선순위 큐에 삽입.
	myPQ.push({ 0, 1, 0 }); // < first : 거리 , second : 노드 인덱스 >

	disArr[1][0] = 0;

    while (!myPQ.empty()) {
        // -를 붙이는 이유는 우선순위 큐를 이용하여 정렬하기 위함이다.
        // (최소힙으로 구현)
        long long int nCost = -get<0>(myPQ.top());

        int now = get<1>(myPQ.top());

        int cnt = get<2>(myPQ.top()); // 포장개수

        myPQ.pop();
        // 이미 담겨 있는 것보다 거리가 크면 넘어간다.
        if (disArr[now][cnt] < nCost) continue;
        // 해당 노드에서 연결된 모든 경로를 확인
        for (int i = 0; i < graph[now].size(); i++) {

            // disSum = 임시 노드 + 현재 노드에서 i로가는 비용
            long long int disSum = nCost + graph[now][i].second;

            // 비용이 작다면 최단경로 테이블 값을 갱신.
            // 도로가 포장을 안했을 경우
            if (disSum < disArr[graph[now][i].first][cnt]) {
                // 임시 노드 업데이트
                disArr[graph[now][i].first][cnt] = disSum;
                // 우선순위 큐에 (거리, 노드 인덱스) 푸시
                myPQ.push({ -disSum, graph[now][i].first, cnt});

            }

            // 비용이 작다면 최단경로 테이블 값을 갱신.
            // 도로가 포장을 했을 경우 이동값은 0
            // 포장할 수 있는 도로의 개수를 넘으면 안된다.
            if (nCost < disArr[graph[now][i].first][cnt + 1] && cnt < K) {
                // 임시 노드 업데이트
                disArr[graph[now][i].first][cnt + 1] = nCost;

                myPQ.push({ -nCost, graph[now][i].first, cnt + 1 });

            }
        }
    }

    long long int result = INF;

    for (int j = 0; j <= K; j++) result = min(disArr[N][j], result);
    
    cout << result;
  
	return 0;
}

