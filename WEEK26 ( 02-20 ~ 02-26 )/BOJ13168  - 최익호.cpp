#include <iostream>
#include <map>
#include <vector>

using namespace std;

constexpr int MAX = 100;
constexpr float INF = 1000000000;

// 티켓이 있는 경우와 없는 경우 2가지 전부 확인
vector<pair<int, float>> graph_No_T[MAX];
vector<pair<int, float>> graph_T[MAX];

// 티켓이 있는 경우와 없는 경우 2가지 전부 확인
float disArr_No_T[MAX][MAX];
float disArr_T[MAX][MAX];

// N : 도시의 개수, R : 내일로 티켓의 가격 
// M : 여행할 도시, K : 교통 수단의 수
int N, R, M, K;

// 도시와 번호 매칭
map<string, int> mapKStr; // Key : 도시 이름, int : 도시의 번호
map<int, string> mapKInt; 

map<string, int> routeKStr = { { "Subway", 0},{ "Bus", 1},{ "Taxi", 2},{ "Airplane", 3}, { "KTX", 4},{ "S-Train", 5},{ "V-Train", 6},{ "ITX-Saemaeul", 7},{ "ITX-Cheongchun", 8}, { "Mugunghwa", 9} };

// 여행하는 순서를 저장하는 백터
vector<int> travelCity;

pair<int, string> temp;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> R;

	for (int i = 0; i < N; i++) {
		cin >> temp.second;
		temp.first = i;
		mapKStr.insert(make_pair(temp.second, temp.first));
		mapKInt.insert(make_pair(temp.first, temp.second));
	}

	// 최단거리 배열 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				disArr_No_T[i][j] = 0;
				disArr_T[i][j] = 0;
			}
			else {
				disArr_No_T[i][j] = INF;
				disArr_T[i][j] = INF;
			}
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> temp.second;
		auto it = mapKStr.find(temp.second);
		travelCity.push_back(it->second);
	}

	cin >> K; // 교통 수단의 수
	string Ru, V, U; // 교통수단, 시작, 도착
	float C; // 비용 (나눈ㅅ)
	
	for (int i = 0; i < K; i++) {
		// 교통 수단은 양방향
		cin >> Ru >> V >> U >> C;

		int ru = routeKStr.find(Ru)->second;
		int v = mapKStr.find(V)->second;
		int u = mapKStr.find(U)->second;
		
		// 티켓이 없을 경우는 그대로 간선 입력
		graph_No_T[v].push_back(make_pair(u, C));
		graph_No_T[u].push_back(make_pair(v, C));

		if (ru == 5 || ru == 6) { // 티켓이 있을 경우 반값
			graph_T[v].push_back(make_pair(u, C / 2));
			graph_T[u].push_back(make_pair(v, C / 2));
		}
		else if (ru == 7 || ru == 8 || ru == 9) { 
			// 티켓이 있을 경우 무료
			graph_T[v].push_back(make_pair(u, 0));
			graph_T[u].push_back(make_pair(v, 0));
		}
		else {
			// 티켓이 있으나 없으나 적용
			graph_T[v].push_back(make_pair(u, C));
			graph_T[u].push_back(make_pair(v, C));
		}

	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < graph_No_T[i].size(); j++) {
			int v = graph_No_T[i][j].first;
			float weight = graph_No_T[i][j].second;
			float weight2 = graph_T[i][j].second;
			if (disArr_No_T[i][v] > weight) disArr_No_T[i][v] = weight;
			if (disArr_T[i][v] > weight2) disArr_T[i][v] = weight2;
		}
	}

	// 플로이드를 이용하여 각 정점의 최소거리 확인
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				disArr_No_T[i][j] = min(disArr_No_T[i][j], disArr_No_T[i][k] + disArr_No_T[k][j]);;
				disArr_T[i][j] = min(disArr_T[i][j], disArr_T[i][k] + disArr_T[k][j]);;
			}
		}
	}


	float res_No_T = 0; // 티켓이 없을 때 비용
	float res_T = 0; // 티켓이 있을때 비용

	// 순차적으로 여행
	for (int i = 0; i < M - 1; i++) {
		int S = i;
		int E = i + 1;
		res_No_T += disArr_No_T[travelCity[S]][travelCity[E]];
		res_T += disArr_T[travelCity[S]][travelCity[E]];
	}

	res_T += R; // 티켓의 비용 추가

	if (res_T >= res_No_T) cout << "No"; // 같아도 No 출력
	else cout << "Yes";

	return 0;
}
