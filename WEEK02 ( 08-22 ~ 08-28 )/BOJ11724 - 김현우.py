import sys

input = sys.stdin.readline
sys.setrecursionlimit(100000)

count = 0

# start 지점부터 dfs 탐색으로 이어진 노드 전부 visited 체크
def dfs(start):
    visited[start] = True
    for nextNode in graph[start]:
        if not visited[nextNode]:
            dfs(nextNode)

n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
visited = [False for _ in range(n+1)]

for _ in range(m):
    start, end = map(int, input().split())
    graph[start].append(end)
    graph[end].append(start)

# 모든 점에 대해 아직 방문하지 않았으면 dfs 탐색을 하고 count 갱신
for i in range(1, n+1):
    if not visited[i]:
        count += 1
        dfs(i)

print(count)
