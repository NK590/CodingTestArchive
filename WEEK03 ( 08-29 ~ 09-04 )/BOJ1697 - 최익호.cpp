#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

#define MAX 100001

int N, K; // N : 수빈이의 위치 K : 동생의 위치
bool visited[MAX]; // 방문 체크
int depth[MAX]; // 깊이

void Init()
{
    cin >> N >> K;
    for (int i = 0; i < MAX; i++)
    {
        visited[i] = false;
    }
}

int BFS(int N, int K)
{
    queue<int> myQueue;
    depth[N] = 0;
    visited[N] = true;
    myQueue.push(N);

    while (!myQueue.empty())
    {
        int pos = myQueue.front();

        if (pos == K)
        {
            return depth[pos]; // 값을 찾으면 깊이 반환
        }

        myQueue.pop();

        if (visited[pos + 1] == 0 && pos + 1 >= 0 && pos + 1 < MAX)
        {
            visited[pos + 1] = true;
            myQueue.push(pos + 1);
            depth[pos + 1] = depth[pos] + 1;
        }
        if (visited[pos - 1] == 0 && pos - 1 >= 0 && pos - 1 < MAX)
        {
            visited[pos - 1] = true;
            myQueue.push(pos - 1);
            depth[pos - 1] = depth[pos] + 1;
        }
        if (visited[pos * 2] == 0 && pos * 2 >= 0 && pos * 2 < MAX)
        {
            visited[pos * 2] = true;
            myQueue.push(pos * 2);
            depth[pos * 2] = depth[pos] + 1;
        }
    }
}

int main()
{
    Init(); // 초기화
    cout << BFS(N, K);
    return 0;
}