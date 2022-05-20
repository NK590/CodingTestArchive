import sys
from collections import deque

MAX_LENGTH = 100001
input = sys.stdin.readline

visited = deque([])
possiblePos = [0 for _ in range(MAX_LENGTH)] # 각각의 위치에 도달할 수 있는 최소 시간

# 시작 지점에서부터 목표 지점까지 bfs 탐색
def bfs(start, end):
    visited.append(start)

    while visited:
        pos = visited.popleft()
        # 목표 지점에 도달했으면 해당 위치까지 걸린 시간 return 후 탐색 종료
        if pos == end:
            return possiblePos[pos]
        # 현위치-1, 현위치+1, 현위치*2 탐색
        for nextPos in [pos+1, pos-1, pos*2]:
            # 위치 범위를 벗어나지 않고 아직 해당 위치를 방문하지 않았을 때
            if 0 <= nextPos < MAX_LENGTH and possiblePos[nextPos] == 0:
                # 다음 위치로 이동 후 다음 위치까지 걸린 시간 입력
                possiblePos[nextPos] = possiblePos[pos] + 1
                visited.append(nextPos)

n, k = map(int, input().split())

print(bfs(n, k))