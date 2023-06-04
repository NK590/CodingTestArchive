def dfs(info, index, sheep, wolf, possible_set):
    global answer, graph
    if info[index] == 0:
        sheep += 1
        answer = max(answer, sheep)
    else:
        wolf += 1

    if wolf >= sheep:
        return

    possible_set.extend(graph[index])
    for entry in possible_set:
        dfs(info, entry, sheep, wolf, [i for i in possible_set if i != entry])


def solution(info, edges):
    global answer, graph
    answer = 0
    n = len(info)
    graph = [[] for _ in range(n)]

    for a, b in edges:
        graph[a].append(b)

    dfs(info, 0, 0, 0, [])

    return answer