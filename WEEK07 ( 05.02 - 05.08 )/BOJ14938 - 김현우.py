import sys
import heapq

input = sys.stdin.readline
INF = sys.maxsize



''' <!-- 플로이드-워셜 알고리즘 풀이법 --> '''

n, m, r = map(int, input().split())
itemCount = list(map(int, input().split()))
# edgeWeightList : 그래프 가중치의 인접 행렬
edgeWeightList = [[INF for _ in range(n)] for __ in range(n)]
# maxItemCount : 아이템 최대 개수
maxItemCount = -INF

for _ in range(r):
    a, b, l = map(int, input().split())
    edgeWeightList[a-1][b-1] = l
    edgeWeightList[b-1][a-1] = l

# 자기 자신으로의 간선 가중치는 0
for i in range(n):
    edgeWeightList[i][i] = 0

# 플로이드-워셜 알고리즘 탬플릿
for k in range(n):
    for i in range(n):
        for j in range(n):
            edgeWeightList[i][j] = min(edgeWeightList[i][j], edgeWeightList[i][k]+edgeWeightList[k][j])

# 인접 행렬의 각각의 행(특정 지점에서 시작하는 최단경로 리스트) 탐색
for weights in edgeWeightList:
    temp = 0
    for i in range(n):
        # 최단경로 간선 가중치가 m보다 작으면 접근 가능 -> 해당 노드의 아이템 개수 추가
        if weights[i] <= m:
            temp += itemCount[i]
    # 각각의 행 탐색시마다 얻을 수 있는 최대 아이템 개수 갱신
    maxItemCount = max(maxItemCount, temp)

print(maxItemCount)



''' <!-- 다익스트라 알고리즘 풀이법 --> '''

n, m, r = map(int, input().split())
itemCount = list(map(int, input().split()))
edgeWeightList = [[] for _ in range(n)]
maxItemCount = -INF

# 다익스트라 알고리즘 적용을 위해 그래프를 다음과 같이 입력받음
# edgeWeightList[x] = [ [y, x->y 사이의 가중치], [z, x->z 사이의 가중치]... ]
for _ in range(r):
    a, b, l = map(int, input().split())
    edgeWeightList[a-1].append([b-1, l])
    edgeWeightList[b-1].append([a-1, l])

# 모든 노드에 대해 탐색
for i in range(n):
    # 다익스트라 알고리즘 탬플릿
    q = []
    distances = [INF for _ in range(n)]
    heapq.heappush(q, [0, i])
    distances[i] = 0

    while q:
        curDist, curVertex = heapq.heappop(q)
        if distances[curVertex] < curDist:
            continue
        for nextVertex, nextDist in edgeWeightList[curVertex]:
            if nextDist + curDist < distances[nextVertex]:
                nextDist += curDist
                distances[nextVertex] = nextDist
                heapq.heappush(q, [nextDist, nextVertex])

    # 다익스트라 알고리즘 수행 후 distances 리스트에는 각 지점까지의 최단경로가 저장되어 있음
    # distances 리스트의 모든 노드에 대해 진입 가능하면 해당 노드의 아이템 개수를 더함
    temp = 0
    for j in range(n):
        if distances[j] <= m:
            temp += itemCount[j]
    
    # 아이템 최대 개수 갱신
    maxItemCount = max(maxItemCount, temp)

print(maxItemCount)