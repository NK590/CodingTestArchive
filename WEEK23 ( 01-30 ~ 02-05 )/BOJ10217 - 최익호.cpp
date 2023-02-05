#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

priority_queue<tuple<long long int, int, int>> myPQ;

long long int disArr[101][10001];

constexpr long long int INF = INT64_MAX;

int T, N, M, K, U, V, C, D, cnt;

long long int Dijstra()
{
    cin >> N >> M >> K;

    // 다익스트라 배열 초기화
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= M; j++)
            disArr[i][j] = INF;

    vector<tuple<int, int, int>> graph[10000];

    for (int i = 0; i < K; i++) {
        cin >> U >> V >> C >> D;
        graph[U].push_back(make_tuple(V, C, D));
    }

    // 우선순위 큐에 삽입.
    myPQ.push({ 0, 1, 0 }); // <거리 , 노드 인덱스 , 비용>

    disArr[1][0] = 0;

    while (!myPQ.empty()) {
        // -를 붙이는 이유는 우선순위 큐를 이용하여 정렬하기 위함이다.
        // (최소힙으로 구현)
        long long int nCost = -get<0>(myPQ.top()); // 현재 최단 거리

        int now = get<1>(myPQ.top()); // 현재 노드

        int money = get<2>(myPQ.top()); // 비용 

        myPQ.pop();

        // 이미 담겨 있는 것보다 거리가 크면 넘어간다.
        if (disArr[now][money] < nCost) continue;

        // 해당 노드에서 연결된 모든 경로를 확인
        for (int i = 0; i < graph[now].size(); i++) {

            // 비용의 범위가 초과된다면 continue
            if (money + get<1>(graph[now][i]) > M) continue;

            // disSum = 임시 노드 + 현재 노드에서 i로가는 비용
            long long int disSum = nCost + get<2>(graph[now][i]);

            // 비용이 작다면 최단경로 테이블 값을 갱신.
            if (disSum < disArr[get<0>(graph[now][i])][money + get<1>(graph[now][i])]) {
                // 임시 노드 업데이트
                disArr[get<0>(graph[now][i])][money + get<1>(graph[now][i])] = disSum;
                // 우선순위 큐에 (거리, 노드 인덱스, 비용) 푸시
                myPQ.push({ -disSum, get<0>(graph[now][i]), money + get<1>(graph[now][i]) });

            }
        }
    }

    long long int result = INF;

    for (int i = 0; i <= M; i++) {
       result = min(disArr[N][i], result);
    }

    return result;
}


int main()
{
    ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
    // cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
    cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> T;

    while (T-- > 0) {
        long long int result = Dijstra();
        if (result == INF) cout << "Poor KCM\n";
        else cout << result << "\n";
    }

    return 0;
}

