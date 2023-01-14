import sys

input = sys.stdin.readline

# dp[x][y] : 마지막 부분이 y 형태인 x의 길이를 가진 타일 경우의 수
# y가 0일 때 가로 (=) 형태, y가 1일 때 세로 (II) 형태
dp = [[0]*2 for _ in range(1001)]
dp[1] = [0, 1]
dp[2] = [2, 1]

n = int(input())

for i in range(3, n+1):
    dp[i] = [2*sum(dp[i-2]) % 10007, sum(dp[i-1]) % 10007]

print(sum(dp[n]) % 10007)