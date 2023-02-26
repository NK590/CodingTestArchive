import sys

input = sys.stdin.readline
INF = sys.maxsize

# 위원회별로 분리시키기 위해 유니온 파인드 자료구조 사용
def find(x):
    if parent[x] != x:
        return find(parent[x])
    return x

def union(x, y):
    x = find(x)
    y = find(y)
    if x < y:
        parent[y] = x
    else:
        parent[x] = y

n = int(input())
# 유니온 파인드에 쓸 부모 인덱스 리스트
parent = [i for i in range(n)]
graph = [[INF for _ in range(n)] for __ in range(n)]
edges = []
ans = []

# 그래프 정보 입력과 함께 union 처리
for _ in range(int(input())):
    a, b = map(int, input().split())
    graph[a-1][b-1] = 1
    graph[b-1][a-1] = 1
    union(a-1, b-1)
    edges.append([a-1, b-1])

# 모든 그룹 정보가 업데이트되지 않았을 수 있기 때문에 한번 더 union 처리
for a, b in edges:
    union(a, b)

for i in range(n):
    graph[i][i] = 0

# 플로이드 워셜
for k in range(n):
    for i in range(n):
        for j in range(n):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

# 위원회 그룹별 사람 관리
group = {node : [] for node in list(set(parent))}
for index, value in enumerate(parent):
    group[value].append(index)

# 그룹별로 그래프를 분리 후, 의사전달시간 최대값이 최소가 되는 대표만 뽑아서 ans에 저장
for key, value_list in group.items():
    len_value_list = len(value_list)

    rep_graph = [[-1 for _ in range(len_value_list)] for __ in range(len_value_list)]
    for i, i_value in enumerate(value_list):
        for j, j_value in enumerate(value_list):
            rep_graph[i][j] = graph[i_value][j_value]

    min_val = min([max(rep_graph[i]) for i in range(len_value_list)])

    for i, i_value in enumerate(value_list):
        if max(rep_graph[i]) == min_val:
            ans.append(i_value + 1)
            break

ans.sort()
print(len(ans))
print(*ans, sep='\n')
