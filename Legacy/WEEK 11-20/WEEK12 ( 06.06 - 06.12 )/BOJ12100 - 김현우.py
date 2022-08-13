import sys
from copy import deepcopy

input = sys.stdin.readline
direction = {0: 'E', 1: 'W', 2: 'S', 3: 'N'} # 방향 지정용 딕셔너리
maxNum = 0 # 가능한 숫자 최대값

# 동서남북 방향으로 보드 기울이기 함수 -> 기울어진 후 보드 return
def tilt(grid, n, dir):
    if dir == 'E': # 동쪽
        for i in range(n):
            start = n - 1
            for j in range(n - 2, -1, -1):
                if grid[i][j]:
                    tmp = grid[i][j]
                    grid[i][j] = 0
                    if grid[i][start] == 0:
                        grid[i][start] = tmp
                    elif grid[i][start] == tmp:
                        grid[i][start] = tmp * 2
                        start -= 1
                    else:
                        start -= 1
                        grid[i][start] = tmp
    elif dir == 'W': # 서쪽
        for i in range(n):
            start = 0
            for j in range(1, n):
                if grid[i][j]:
                    tmp = grid[i][j]
                    grid[i][j] = 0
                    if grid[i][start] == 0:
                        grid[i][start] = tmp
                    elif grid[i][start] == tmp:
                        grid[i][start] = tmp * 2
                        start += 1
                    else:
                        start += 1
                        grid[i][start] = tmp
    elif dir == 'S': # 남쪽
        for j in range(n):
            start = n - 1
            for i in range(n - 2, -1, -1):
                if grid[i][j]:
                    tmp = grid[i][j]
                    grid[i][j] = 0
                    if grid[start][j] == 0:
                        grid[start][j] = tmp
                    elif grid[start][j] == tmp:
                        grid[start][j] = tmp * 2
                        start -= 1
                    else:
                        start -= 1
                        grid[start][j] = tmp
    elif dir == 'N': # 북쪽
        for j in range(n):
            start = 0
            for i in range(1, n):
                if grid[i][j]:
                    tmp = grid[i][j]
                    grid[i][j] = 0
                    if grid[start][j] == 0:
                        grid[start][j] = tmp
                    elif grid[start][j] == tmp:
                        grid[start][j] = tmp * 2
                        start += 1
                    else:
                        start += 1
                        grid[start][j] = tmp
    return grid

# 동서남북 방향으로 기울이기 dfs 재귀탐색
def dfs(grid, n, depth):
    global maxNum
    # 기울이기 조작 5회 시행 시 보드의 각 숫자 최대값 갱신 후 종료
    if depth == 5:
        for i in range(n):
            for j in range(n):
                maxNum = max(maxNum, grid[i][j])
        return
    
    # 동서남북 재귀 탐색
    for i in range(4):
        tempGrid = tilt(deepcopy(grid), n, direction[i])
        dfs(tempGrid, n, depth + 1)

n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

dfs(grid, n, 0)

print(maxNum)