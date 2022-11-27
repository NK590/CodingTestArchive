#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#define MAX 100 + 1
using namespace std;
int N;


vector<int>graph[MAX];
int visit[MAX];

void Reset()
{
    // memset(visit, 0, sizeof(visit)); 
    // 위코드와 같은 역할
    for (int i = 0; i < N; i++)
    {
        visit[i] = 0;
    }
}

void Dfs(int node) 
{
    stack<int> s;    
    s.push(node);

    while (!s.empty())
    {
        int cur = s.top();
        s.pop();

        for (int i = 0; i < graph[cur].size(); i++)
        {
            // 이미 방문을 했다면 스킵하기
            if (visit[graph[cur][i]] == 1)
                continue;

            visit[graph[cur][i]] = 1;
            s.push(graph[cur][i]);
        }
    }
}
int main() 
{
    cin >> N;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            int path;
            cin >> path;
            // 해당 위치로 가는 경로가 있다면
            if (path == 1)
                graph[i].push_back(j);
        }
    }

    for (int i = 0; i < N; i++) 
    {
        // 각 노드마다 방문여부 초기화 해주고
        Reset();
        // 순서대로 방문가능한곳부터 dfs 탐색 시작
        Dfs(i);
        for (int j = 0; j < N; j++)
            cout << visit[j] << " ";
        cout << "\n";
    }
}