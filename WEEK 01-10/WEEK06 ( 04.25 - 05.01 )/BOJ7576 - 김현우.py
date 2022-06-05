import sys
from collections import deque

input = sys.stdin.readline

visited = deque([])
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs():
    while visited:
        x, y = visited.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == 0:
                grid[nx][ny] = grid[x][y] + 1
                visited.append([nx, ny])

m, n = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

for i in range(n):
    for j in range(m):
        if grid[i][j] == 1:
            visited.append([i, j])

bfs()

is_all_ripe = True
max_day = 0

for row in grid:
    max_day = max(max_day, max(row))
    for col in row:
        if col == 0:
            is_all_ripe = False

if is_all_ripe:
    print(max_day - 1)
else:
    print(-1)