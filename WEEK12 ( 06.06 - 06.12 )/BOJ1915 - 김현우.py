import sys

input = sys.stdin.readline
maxLen = 0 # 1로 된 정사각형 한 변의 최대 길이

n, m = map(int, input().split())
grid = [list(map(int, list(input().rstrip()))) for _ in range(n)]

# dp[i][j] : (i-1, j-1)를 우하단 꼭지점으로 하는 1로 된 정사각형의 한 변의 최대 길이
dp = [[0 for _ in range(m + 1)] for __ in range(n + 1)]

# dp 갱신
for i in range(1, n + 1):
    for j in range(1, m + 1):
        # grid의 (i-1, j-1) 값이 1이면 갱신 가능
        if grid[i - 1][j - 1] == 1:
            # dp의 좌단, 상단, 좌상단 값 중 제일 큰 값 + 1
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1

# dp 계산 후 maxLen 갱신
for i in range(n + 1):
    for j in range(m + 1):
        maxLen = max(maxLen, dp[i][j])

# 구하고자 하는 값은 정사각형의 넓이이므로 maxLen 제곱 계산
print(maxLen ** 2)