#include <iostream>
#include<vector>
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

void Dfs(int x) 
{
    for (int i = 0; i < graph[x].size(); i++)
    {
        // 해당 위치로 가는길이 있는데 아직 방문하지 않았다면
        if (!visit[graph[x][i]])
        {
            visit[graph[x][i]] = 1;
            Dfs(graph[x][i]);
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