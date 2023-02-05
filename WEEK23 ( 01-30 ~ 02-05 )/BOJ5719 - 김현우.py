import sys
from heapq import heappush, heappop
from collections import deque

input = sys.stdin.readline

# 다익스트라 탐색
def dijkstra(graph, start):
    distances = {node : sys.maxsize for node in graph}
    distances[start] = 0
    q = []
    heappush(q, [distances[start], start])

    while q:
        cur_distance, cur_destination = heappop(q)

        if distances[cur_destination] < cur_distance:
            continue

        for next_destination, next_distance in graph[cur_destination].items():
            distance = cur_distance + next_distance
            if distance < distances[next_destination]:
                distances[next_destination] = distance
                heappush(q, [distance, next_destination])

    return distances

# 최단경로를 지우기 위한 bfs 탐색
def bfs(distances, start, end):
    q = deque([end])
    while q:
        cur_node = q.popleft()
        # 최단경로가 한 가지가 아닐 수도 있기 때문에 break가 아닌 continue 처리
        if start == cur_node:
            continue
        # 최단경로를 타고 역으로 거슬러 올라가며 지워야 될 최단경로 간선 업데이트
        for prev_node, prev_distance in path_list[cur_node]:
            if distances[prev_node] + graph[prev_node][cur_node] == distances[cur_node]:
                if [prev_node, cur_node] not in remove_list:
                    remove_list.append([prev_node, cur_node])
                    q.append(prev_node)

while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    start, end = map(int, input().split())

    graph = {node : {} for node in range(n)}
    path_list = [[] for _ in range(n)]

    for _ in range(m):
        a, b, c = map(int, input().split())
        graph[a][b] = c
        # bfs 탐색을 위해 기존 그래프와는 역방향으로 거슬러 올라가게끔 반대로 입력받음
        path_list[b].append([a, c])

    # 다익스트라 탐색 후, bfs 탐색을 돌며 지워야 될 최단경로 간선 업데이트
    distances = dijkstra(graph, start)
    remove_list = []
    bfs(distances, start, end)

    # 최단경로 간선 삭제
    for a, b in remove_list:
        del graph[a][b]

    # 기존 그래프에서 최단경로 삭제 후 다시 다익스트라 탐색으로 최단경로 구하기
    distances = dijkstra(graph, start)

    # 거의 최단경로 탐색 후 최단경로가 존재하면 그 길이를, 아니면 -1 출력
    print(distances[end] if distances[end] != sys.maxsize else -1)