import sys

input = sys.stdin.readline
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
area_num = 0

# dfs로 안전영역 덩어리 지우기
def dfs(_i, _j):
    visited[_i][_j] = True
    stack = [[_i, _j]]
    while stack:
        x, y = stack.pop()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx < n and 0 <= ny < n:
                if not visited[nx][ny] and grid[nx][ny] > height:
                    visited[nx][ny] = True
                    stack.append([nx, ny])

n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# 물의 높이(height)를 단계적으로 높이면서 dfs 탐색으로 안전 영역 최대개수 갱신
# 문제 오류인지는 몰라도 height 초기값을 1이 아닌 0부터 시작해야 통과됨
for height in range(101):
    visited = [[False for _ in range(n)] for __ in range(n)]
    count = 0
    for i in range(n):
        for j in range(n):
            if not visited[i][j] and grid[i][j] > height:
                dfs(i, j)
                count += 1
    area_num = max(area_num, count)

print(area_num)