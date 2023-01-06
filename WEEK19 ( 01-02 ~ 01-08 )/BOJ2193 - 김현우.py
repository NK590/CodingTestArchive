import sys

input = sys.stdin.readline

n = int(input())
# dp[x][y] : x자리인데 마지막 자리수가 y로 끝나는 이친수
dp = [[0]*2 for _ in range(n+1)]
dp[1][1] = 1

for i in range(2, n+1):
    dp[i][0] = dp[i-1][0] + dp[i-1][1]
    dp[i][1] = dp[i-1][0]

print(dp[-1][0] + dp[-1][1])