import sys

input = sys.stdin.readline

# DFS 탐색 함수
def dfs(start):
    stack = [start]
    count = 0
    # DFS 스택이 빌 때까지 탐색
    while stack:
        nextNum = stack.pop()
        for i in range(len(graph[nextNum])):
            # nextNum 노드와 연결되어 있는 노드가 존재하고 아직 그 노드에 방문하지 않았을 시 -> 해당 노드로 탐색
            if graph[nextNum][i] != 0 and visited[nextNum][i] == 0:
                stack.append(graph[nextNum][i])
                visited[nextNum][i] = 1
                count += 1 # 채널이 바뀌는 수 갱신 후 nextNum 노드 탐색 종료
                break
            if visited[nextNum][i] == 1: # 이미 방문한 적이 있느 노드 -> 사이클을 의미하므로 -1 return
                return -1
    # DFS 탐색 종료 후 총 채널 변경 수 return
    return count

n, m, p = map(int, input().split())
graph = [[] for _ in range(m+1)] # 그래프 연결상태 리스트
visited = [[] for _ in range(m+1)] # 그래프 방문 여부 (초기값 0)
for i in range(n):
    a, b = map(int, input().split())
    graph[b].append(a)
    visited[b].append(0)

print(dfs(p))