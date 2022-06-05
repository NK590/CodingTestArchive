import sys

input = sys.stdin.readline

n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# 3차원 dp 리스트 dp[z][x][y] : 해당 칸에 접근 가능한 경우의 수
# x, y : grid의 x, y 좌표
# z : 어느 방향 파이프를 타고 왔는지 체크 (0 : 왼쪽->오른쪽, 1 : 위->아래, 2 : 대각선)
dp = [[[0 for _ in range(n)] for __ in range(n)] for ___ in range(3)]

# 초기 파이프 위치는 시작점에서 가로로 연결되어 있음
dp[0][0][1] = 1

# grid의 첫 행 초기화
for i in range(2, n):
    if grid[0][i] == 0:
        dp[0][0][i] = dp[0][0][i-1]

# grid 내 모든 지점에 대해 dp 갱신
for row in range(1, n):
    for col in range(1, n):
        # 파이프가 대각선으로 들어올 경우
        if grid[row][col] == 0 and grid[row][col-1] == 0 and grid[row-1][col] == 0:
            dp[2][row][col] = dp[0][row-1][col-1] + dp[1][row-1][col-1] + dp[2][row-1][col-1]

        if grid[row][col] == 0:
            # 파이프가 가로로 들어올 경우
            dp[0][row][col] = dp[0][row][col-1] + dp[2][row][col-1]
            # 파이프가 세로로 들어올 경우
            dp[1][row][col] = dp[1][row-1][col] + dp[2][row-1][col]

# 총 경우의 수 = grid[-1][-1] 지점에서의 dp값의 총합
print(sum(dp[i][-1][-1] for i in range(3)))