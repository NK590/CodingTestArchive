import sys
import heapq

input = sys.stdin.readline

def dijkstra(graph, start):
    dist = {node: sys.maxsize for node in graph}
    dist[start] = 0
    queue = []
    heapq.heappush(queue, [dist[start], start])

    while queue:
        current_dist, current_node = heapq.heappop(queue)
        if dist[current_node] < current_dist:
            continue
        for edge, weight in graph[current_node].items():
            new_distance = current_dist + weight
            if new_distance < dist[edge]:
                dist[edge] = new_distance
                heapq.heappush(queue, [new_distance, edge])
    return dist

n, m, x = map(int, input().split())
graph = {node: {} for node in range(1, n+1)}
for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a][b] = c

ans = 0
dist = dijkstra(graph, x)

# 모든 마을 번호 num에 대해 오고 가는 시간을 합쳐서 최대값 갱신
# 단방향 도로이기 때문에 단순히 2를 곱하면 안됨
for num in graph.keys():
    ans = max(ans, dijkstra(graph, num)[x] + dist[num])

print(ans)