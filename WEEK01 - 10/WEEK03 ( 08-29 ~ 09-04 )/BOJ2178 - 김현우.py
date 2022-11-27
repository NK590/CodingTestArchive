import sys
from collections import deque

input = sys.stdin.readline
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

n, m = map(int, input().split())
grid = [list(map(int, list(input().rstrip()))) for _ in range(n)]
visited = [[False for _ in range(m)] for __ in range(n)]

# deque를 이용한 bfs 탐색 시작 -> 시작점은 (0, 0)
q = deque()
q.append([0, 0])
visited[0][0] = True

# 입력받은 grid 2차원 리스트에 최단 경로를 직접 갱신하며 탐색
while q:
    x, y = q.popleft()
    # 현재 위치에서의 최단거리값
    curVal = grid[x][y]
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        # grid 범위 안에 있을 시
        if 0 <= nx < n and 0 <= ny < m:
            # 아직 방문하지 않았고 벽이 아닐 시
            if not visited[nx][ny] and grid[nx][ny] != 0:
                # 방문여부 갱신, 최단거리 갱신, deque 리스트 갱신
                visited[nx][ny] = True
                grid[nx][ny] = curVal + 1
                q.append([nx, ny])

# 우하단 목표점의 최단 경로값 출력
print(grid[-1][-1])