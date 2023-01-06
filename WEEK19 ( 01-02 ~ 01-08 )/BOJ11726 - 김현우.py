import sys

input = sys.stdin.readline

n = int(input())
# dp[x][y] = 총 길이가 x인 타일 맨 마지막이 y로 끝나는 경우
# (y가 0일 때 가로로 끝나는 경우 (=), y가 1일 때 세로로 끝나는 경우 (II))
dp = [[0]*2 for _ in range(n+1)]
dp[0][0] = 0
dp[0][1] = 1
dp[1][1] = 1

for i in range(2, n+1):
    dp[i][0] = (dp[i-2][0] + dp[i-2][1]) % 10007
    dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % 10007

print((dp[-1][0] + dp[-1][1]) % 10007)