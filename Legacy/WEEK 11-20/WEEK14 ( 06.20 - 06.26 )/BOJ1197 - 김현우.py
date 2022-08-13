import sys
from heapq import *

input = sys.stdin.readline

# Kruskal 알고리즘 -> Union Find(Disjoint Set) 이용
# 1. 우선 모든 정점을 독립적인 집합으로 간주하고, 간선들을 정렬
# 2. 간선이 있는 두 정점의 root를 찾음
# 3. root가 다르다면 두 정점을 연결시킴

def union_find(x):
    if x != vertexRoot[x]:
        vertexRoot[x] = union_find(vertexRoot[x])
    return vertexRoot[x]

vertex, edge = map(int, input().split())
vertexRoot = [i for i in range(vertex + 1)] # vertexRoot[index] : index번째 노드의 연결요소 중 가장 작은 값, 초기값은 자기 자신

edgeList = [list(map(int, input().split())) for _ in range(edge)]
edgeList.sort(key = lambda x : x[2]) # weight값을 기준으로 오름차순 정렬

answer = 0
for start, end, weight in edgeList:
    startRoot = union_find(start)
    endRoot = union_find(end)
    if startRoot != endRoot: # 두 정점의 root가 다르면 두 정점을 연결
        if startRoot > endRoot:
            vertexRoot[startRoot] = endRoot
        else:
            vertexRoot[endRoot] = startRoot
        answer += weight # 해당 가중치를 추가

print(answer)

# Prim 알고리즘 -> heap 이용
# 1. 임의의 정점을 선택 후 해당 정점에서 갈 수 있는 간선을 최소 heap에 넣음
# 2. 그 heap에서 pop을 하여 (최소값을 뽑아), 그 간선에서 이어지는 정점을 찾음
# 3. 해당 정점을 방문하지 않았다면 heap에 넣고 반복

vertex, edge = map(int, input().split())
visited = [False for _ in range(vertex+1)] # 각 정점별 방문 여부 확인
edgeList = [[] for _ in range(vertex+1)]

heap = [[0, 1]] # [시작 가중치, 시작 정점번호]

for _ in range(edge):
    start, end, weight = map(int, input().split())
    edgeList[start].append([weight, end]) # edgeList에 간선정보 입력 시 주의점
    edgeList[end].append([weight, start]) # heappop 사용 시 간선 가중치 최소값을 뽑아야 하므로, weight를 먼저 입력

answer = 0
count = 0
while heap:
    if count == vertex: # 모든 점을 한번씩 방문했을 시 탐색 종료
        break
    weight, start = heappop(heap)
    if not visited[start]:
        visited[start] = True
        answer += weight
        count += 1
        for nextEdge in edgeList[start]:
            heappush(heap, nextEdge)

print(answer)