import sys

input = sys.stdin.readline

MAX_LENGTH = 31

# dp[n] : n이 주어졌을 때 타일을 채울 수 있는 경우의 수
dp = [0 for _ in range(MAX_LENGTH)]
# 아무 것도 없는 상태도 하나의 경우의 수로 침 -> 하술할 dp 점화식에서 유용
dp[0] = 1
dp[2] = 3

# n이 홀수면 경우의 수 = 0 -> 홀수인 경우는 배제
for i in range(4, MAX_LENGTH, 2):
    # i번째 경우의 수
    # = 3 * 바로 전 i-2번째 경우의 수 (블럭이 가로로 이어지지 않은 경우)
    # + 2 * 그 이전 모든 경우의 수 (블럭이 가로로 이어진 경우)
    dp[i] = 3 * dp[i-2] + 2 * sum(dp[:i-3])

n = int(input())
print(dp[n])