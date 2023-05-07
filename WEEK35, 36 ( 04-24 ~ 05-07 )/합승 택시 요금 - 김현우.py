import sys

INF = sys.maxsize

# 프로그래머스 - 합승 택시 요금 (LV3)

def solution(n, s, a, b, fares):
    answer = INF
    graph = [[INF for _ in range(n + 1)] for __ in range(n + 1)]

    for i, j, cost in fares:
        graph[i][j] = cost
        graph[j][i] = cost

    for i in range(1, n + 1):
        graph[i][i] = 0

    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

    for i in range(1, n + 1):
        answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b])

    return answer