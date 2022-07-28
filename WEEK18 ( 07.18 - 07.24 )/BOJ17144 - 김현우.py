import sys
from math import floor
from copy import deepcopy

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

input = sys.stdin.readline

# x, y 위치 확산 함수 -> deepcopy 이용
def diffuse(grid):
    grid_copy = deepcopy(grid)
    for x in range(r):
        for y in range(c):
            if grid[x][y] != 0 and grid[x][y] != -1:
                diff_val = floor(grid[x][y]/5)
                for k in range(4):
                    nx = x + dx[k]
                    ny = y + dy[k]
                    if 0 <= nx < r and 0 <= ny < c and grid[nx][ny] != -1:
                        grid_copy[nx][ny] += diff_val
                        grid_copy[x][y] -= diff_val
    return grid_copy

# 위쪽 공기청정기 공기 순환
def top_air_circulate(x, grid):
    temp = 0
    for i in range(1, c):
        grid[x][i], temp = temp, grid[x][i]
    for i in range(x-1, -1, -1):
        grid[i][c-1], temp = temp, grid[i][c-1]
    for i in range(c-2, -1, -1):
        grid[0][i], temp = temp, grid[0][i]
    for i in range(1, x):
        grid[i][0], temp = temp, grid[i][0]

# 아래쪽 공기청정기 공기 순환
def bottom_air_circulate(x, grid):
    temp = 0
    for i in range(1, c):
        grid[x][i], temp = temp, grid[x][i]
    for i in range(x+1, r):
        grid[i][c-1], temp = temp, grid[i][c-1]
    for i in range(c-2, -1, -1):
        grid[r-1][i], temp = temp, grid[r-1][i]
    for i in range(r-2, x, -1):
        grid[i][0], temp = temp, grid[i][0]

r, c, t = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(r)]

# 위쪽 공기청정기, 아래쪽 공기청정기 위치 체크
top = 0
for i in range(r):
    if grid[i][0] == -1:
        top = i
        break
bottom = top + 1

# 1. 확산 2. 공기청정기 루틴을 t회 반복
for _ in range(t):
    grid = diffuse(grid)
    top_air_circulate(top, grid)
    bottom_air_circulate(bottom, grid)

# 남은 미세먼지 양 더하기
ans = 0
for i in range(r):
    for j in range(c):
        ans += grid[i][j]

# 공기청정기 위치에 있는 두 개의 -2만큼을 더해서 출력
print(ans+2)