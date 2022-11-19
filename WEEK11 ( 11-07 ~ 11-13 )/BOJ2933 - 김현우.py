import sys
from collections import deque

input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
INF = sys.maxsize

# 미네랄 파괴 로직
def destroy(i, left):
    i, j = r - i, 0
    if left == 1:
        for k in range(c):
            if grid[i][k] == 'x':
                grid[i][k] = '.'
                j = k
                break
    else:
        for k in range(c-1, -1, -1):
            if grid[i][k] == 'x':
                grid[i][k] = '.'
                j = k
                break

    for k in range(4):
        ni = i + dx[k]
        nj = j + dy[k]
        if 0 <= ni < r and 0 <= nj < c:
            if grid[ni][nj] == 'x':
                dq.append([ni, nj])

# 파괴 후 bfs 탐색 로직
def bfs(x, y):
    q = deque()
    check = [[0 for __ in range(c)] for _ in range(r)]
    fall_list = []
    q.append([x, y])
    check[x][y] = 1
    while q:
        x, y = q.popleft()
        if x == r-1:
            return
        if grid[x+1][y] == '.':
            fall_list.append([x, y])
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < r and 0 <= ny < c:
                if grid[nx][ny] == 'x' and not check[nx][ny]:
                    check[nx][ny] = 1
                    q.append([nx, ny])

    fall(check, fall_list)

# 공중에 떠있는 미네랄 덩어리 떨어트리기 로직
def fall(check, fall_list):
    k, flag = 1, 0
    while True:
        for i, j in fall_list:
            if i + k == r-1:
                flag = 1
                break
            if grid[i+k+1][j] == 'x' and not check[i+k+1][j]:
                flag = 1
                break
        if flag:
            break
        k += 1

    for i in range(r-2, -1, -1):
        for j in range(c):
            if grid[i][j] == 'x' and check[i][j]:
                grid[i][j] = '.'
                grid[i+k][j] = 'x'

r, c = map(int, input().split())
grid = [list(input().rstrip()) for _ in range(r)]
n = int(input())
input_list = list(map(int, input().split()))

dq = deque()
left = 1

for i in range(n):
    index = input_list[i]
    destroy(index, left)

    while dq:
        x, y = dq.popleft()
        bfs(x, y)

    left *= -1

for i in range(r):
    print(''.join(grid[i]))