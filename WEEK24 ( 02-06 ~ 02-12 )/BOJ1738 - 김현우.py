import sys

input = sys.stdin.readline

# 벨만-포드 구현
def bellman_ford(graph):
    for i in range(n):
        for node in graph:
            for neighbor in graph[node]:
                if distances[neighbor] < distances[node] + graph[node][neighbor]:
                    distances[neighbor] = distances[node] + graph[node][neighbor]
                    # 경로가 갱신될때마다 prev 리스트도 갱신
                    prev[neighbor] = node
                    # n-1번 반복 후에도 경로 갱신이 된다면 양의 사이클 -> 이 경우에는 해당 경로값을 INF로 처리
                    if i == n-1:
                        distances[neighbor] = sys.maxsize

n, m = map(int, input().split())
graph = {node : {} for node in range(1, n+1)}
# 금품의 양이 '최대'가 되어야 하므로, 초기값을 -INF에서 시작해서 최대값을 갱신해나감
distances = {node : -sys.maxsize for node in range(1, n+1)}
distances[1] = 0
# 경로를 추적하기 위한 리스트 (prev[x] = y : 최단경로 트리에서 x번 노드의 부모 노드가 y임)
prev = [0 for _ in range(n+1)]
for _ in range(m):
    u, v, w = map(int, input().split())
    try:
        graph[u][v] = max(graph[u][v], w)
    except KeyError:
        graph[u][v] = w

bellman_ford(graph)

if distances[n] != sys.maxsize:
    ans = [n]
    node = n
    while node != 1:
        node = prev[node]
        ans.append(node)
    print(*ans[::-1])
else:
    print(-1)