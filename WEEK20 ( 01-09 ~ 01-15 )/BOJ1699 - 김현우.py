import sys

input = sys.stdin.readline

n = int(input())

# dp[x] : x를 표현할 수 있는 제곱수의 최소 개수
dp = [x for x in range(n+1)]

# 1부터 n까지 모든 i에 대해, i보다 작고 i가 j의 제곱수만큼 차이가 나는 모든 경우를 탐색하며 dp 갱신
for i in range(1, n+1):
    for j in range(1, int(i**0.5)+1):
        dp[i] = min(dp[i], dp[i-j**2]+1)

print(dp[n])