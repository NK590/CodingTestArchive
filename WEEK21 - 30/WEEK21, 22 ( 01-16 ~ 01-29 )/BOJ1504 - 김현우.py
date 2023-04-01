import sys
import heapq

INF = sys.maxsize

def dijkstra(graph, start):
    dist = {node: INF for node in graph}
    dist[start] = 0
    queue = []
    heapq.heappush(queue, [dist[start], start])

    while queue:
        current_dist, current_node = heapq.heappop(queue)
        if dist[current_node] < current_dist:
            continue
        for edge, weight in graph[current_node].items():
            distance = current_dist + weight
            if distance < dist[edge]:
                dist[edge] = distance
                heapq.heappush(queue, [distance, edge])

    return dist

v, e = map(int, sys.stdin.readline().split())
graph = {x: {} for x in range(1, v + 1)}

for _ in range(e):
    a, b, c = map(int, sys.stdin.readline().split())
    try:
        graph[a][b] = min(graph[a][b], c)
        graph[b][a] = min(graph[b][a], c)
    except KeyError:
        graph[a][b] = c
        graph[b][a] = c

# 시작 -> v1 -> v2 -> 끝으로 가는 경우, 시작 -> v2 -> v1 -> 끝으로 가는 두 경우의 수를 고려
v1, v2 = map(int, sys.stdin.readline().split())

x1 = dijkstra(graph, 1)[v1]
x2 = dijkstra(graph, v1)[v2]
x3 = dijkstra(graph, v2)[v]
y1 = dijkstra(graph, 1)[v2]
y2 = dijkstra(graph, v2)[v1]
y3 = dijkstra(graph, v1)[v]

# 두 경우의 수 모두에서 갈 수 없는 루트가 존재할 경우 -1 출력, 아니면 둘 중 작은 값을 출력
if (x1 == INF or x2 == INF or x3 == INF) and (y1 == INF or y2 == INF or y3 == INF):
    print(-1)
else:
    print(min(x1 + x2 + x3, y1 + y2 + y3))