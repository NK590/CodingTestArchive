import sys

input = sys.stdin.readline

n, k = map(int, input().split())
coins = [int(input()) for _ in range(n)]

dp = [0 for _ in range(k+1)]
dp[0] = 1

for coin in coins:
    for index in range(1, k+1):
        if index >= coin:
            dp[index] += dp[index-coin]

print(dp[k])