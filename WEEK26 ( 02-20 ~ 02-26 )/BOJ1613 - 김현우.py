import sys

input = sys.stdin.readline
INF = sys.maxsize

n, k = map(int, input().split())
dp = [[INF for _ in range(n)] for __ in range(n)]

for _ in range(k):
    a, b = map(int, input().split())
    dp[a - 1][b - 1] = 1

for k in range(n):
    for i in range(n):
        for j in range(n):
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])

for _ in range(int(input())):
    a, b = map(int, input().split())

    # 두 사건 사이에 전후관계가 존재하지 않을 때
    if dp[a - 1][b - 1] == INF and dp[b - 1][a - 1] == INF:
        print(0)
    # a가 b보다 먼저 일어났을 때
    elif dp[a - 1][b - 1] != INF:
        print(-1)
    # b가 a보다 먼저 일어났을 때
    else:
        print(1)