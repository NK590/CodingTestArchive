import sys
from collections import deque

input = sys.stdin.readline
dfs_list = []
bfs_list = []

# dfs 탐색 함수
def dfs(start):
    visited[start] = True
    dfs_list.append(start)
    for nextNode in range(1, n+1):
        if not visited[nextNode] and graph[start][nextNode]:
            dfs(nextNode)

# bfs 탐색 함수
def bfs(start):
    q = deque([start])
    visited[start] = True
    while q:
        startNode = q.popleft()
        bfs_list.append(startNode)
        for nextNode in range(1, n+1):
            if not visited[nextNode] and graph[startNode][nextNode]:
                q.append(nextNode)
                visited[nextNode] = True

n, m, v = map(int, input().split())

# graph를 연결 리스트 형식으로 입력
# i 노드와 j 노드가 연결되어 있으면 graph[i][j] == True, 아니면 False
graph = [[False for _ in range(n+1)] for __ in range(n+1)]
for i in range(m):
    start, end = map(int, input().split())
    graph[start][end] = True
    graph[end][start] = True

visited = [False for _ in range(n+1)]
dfs(v)

visited = [False for _ in range(n+1)]
bfs(v)

print(*dfs_list)
print(*bfs_list)