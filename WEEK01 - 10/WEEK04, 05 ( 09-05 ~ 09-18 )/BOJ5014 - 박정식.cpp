#define MAX 1000000 + 1
#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
int visit[MAX];

int main()
{
	// F : 꼭대기층, S : 강호위치(시작층), G : 목표층, U : UP버튼을 누를때 마다 올라가는 층수, D : Down버튼을 누를때 마다 내려가는 층수
	cin >> F >> S >> G >> U >> D;
	
	// 시작층이 도착층이라면 바로 끝내버린다.
	if (S == G)
	{
		cout << 0 << endl;
		return 0;
	}

	// 큐선언 하고 시작층을 q에 넣어서 시작층부터 탐색하기
	queue<int> q;
	q.push(S);
	visit[S] = 1;

	// 큐에 더이상 원소가 없을때 까지 탐색하기
	while (!q.empty())
	{
		// cur = 현재층
		// 큐에서 데이터를 하나씩 꺼내서 현재층 위치 바꾸기
		int cur = q.front();
		q.pop();
		// 목표층에 도달을 했다면
		if (cur == G)
			break;
		
		// 다음 도착층 위로 먼저 올라가보기
		int nextFloor = cur + U;
		// visit배열에 0이 있다면 방문하지 않은 상태입니다.
		// 다음도착층이 꼭대기층 이하여야하고 방문 하지 않았다면 if문 실행
		if (nextFloor <= F && visit[nextFloor] == 0)
		{
			// 큐에 다음탐색 출발지점 담아주기
			q.push(nextFloor);
			// 방문체크용 변수에 걸리는 시간도 표현하기 위해 1씩 더해주기
			visit[nextFloor] = visit[cur] + 1;			
		}

		// 다음 도착층은 아래로도 내려가보기
		nextFloor = cur - D;		
		// visit배열에 0이 있다면 방문하지 않은 상태입니다.
		// 다음도착층이 0층 이상이여야하고 방문 하지 않았다면 if문 실행
		if (nextFloor >= 1 && visit[nextFloor] == 0)
		{
			// 큐에 다음탐색 출발지점 담아주기
			q.push(nextFloor);
			// 방문체크용 변수에 걸리는 시간도 표현하기 위해 1씩 더해주기
			visit[nextFloor] = visit[cur] + 1;			
		}
	}

	// 시작할때 1을 더해주고 시작하니까 1빼고 방문한시간 출력해주기
	if (visit[G] != 0)
		cout << visit[G]-1 << endl;
	// 모든 탐색을 마쳤는데도 꼭대기층을 방문하지 않았다면 출력해주기
	else
		cout << "use the stairs" << endl;

	return 0;
}