import sys

input = sys.stdin.readline

# 내일로 여행시 무료인 열차, 반값인 열차
free = {"Mugunghwa", "ITX-Saemaeul", "ITX-Cheongchun"}
half = {"S-Train", "V-Train"}

n, r = map(int, input().split())
names = list(map(str, input().split()))

# 도시 이름과 인덱스 바인딩
name_to_index = {names[i]: i for i in range(n)}

# 여행해야 될 도시를 순차적으로 인덱스화시켜 저장
m = int(input())
target_indices = [name_to_index[name] for name in list(map(str, input().split()))]

# 내일로 티켓이 있는 경우, 없이 여행하는 경우를 나눔
graph = [[sys.maxsize for _ in range(n)] for __ in range(n)]
graph_with_ticket = [[sys.maxsize for _ in range(n)] for __ in range(n)]

# 열차, 경로별 운임 입력
for _ in range(int(input())):
    typee, s, e, cost = map(str, input().split())
    s_index = name_to_index[s]
    e_index = name_to_index[e]
    cost = int(cost)

    graph[s_index][e_index] = min(graph[s_index][e_index], cost)
    graph[e_index][s_index] = min(graph[e_index][s_index], cost)

    if typee in free:
        cost = 0
    elif typee in half:
        cost /= 2
    graph_with_ticket[s_index][e_index] = min(graph_with_ticket[s_index][e_index], cost)
    graph_with_ticket[e_index][s_index] = min(graph_with_ticket[e_index][s_index], cost)

# 플로이드 워셜
for k in range(n):
    for i in range(n):
        for j in range(n):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
            graph_with_ticket[i][j] = min(graph_with_ticket[i][j], graph_with_ticket[i][k] + graph_with_ticket[k][j])

# 각각의 경로별 운임 취합
dist = 0
dist_with_ticket = 0
for i in range(m - 1):
    fr, to = target_indices[i], target_indices[i + 1]
    dist += graph[fr][to]
    dist_with_ticket += graph_with_ticket[fr][to]

print("Yes" if dist > dist_with_ticket + r else "No")