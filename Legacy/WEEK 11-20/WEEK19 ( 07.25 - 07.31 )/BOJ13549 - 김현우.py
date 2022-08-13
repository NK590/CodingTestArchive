import sys
from collections import deque

input = sys.stdin.readline
MAX_LENGTH = 100000
visited = [-1 for _ in range(MAX_LENGTH+1)] # 방문 여부 체크용 리스트 -> 인덱스가 위치, 값은 최단 회수

n, k = map(int, input().split())

visit_deq = deque([n])      # 방문해야 할 좌표 deque
visited[n] = 0              # 시작점 n은 무조건 방문하므로 0으로 초기화

while visit_deq:
    cur_pos = visit_deq.popleft()

    # 목표점(k) 최초 도달 시 이동 회수 출력 후 종료
    if cur_pos == k:
        print(visited[cur_pos])
        break

    # 현재 좌표값*2 로 이동할 경우
    # 아직 방문하지 않은 지점이라면 그 지점 visited 리스트를 현 지점과 동일 값으로 갱신
    # 이 때 deque의 뒤에 append하지 않고 앞으로 append하여 먼저 탐색함 -> 자세한 내용은 0-1 BFS 참조
    if 0 <= cur_pos*2 <= MAX_LENGTH and visited[cur_pos*2] == -1:
        visited[cur_pos*2] = visited[cur_pos]
        visit_deq.appendleft(cur_pos*2)

    # 현재 좌표값 +- 1로 이동할 경우
    for i in [cur_pos-1, cur_pos+1]:
        if 0 <= i <= MAX_LENGTH and visited[i] == -1:
            visited[i] = visited[cur_pos] + 1
            visit_deq.append(i)