import sys

input = sys.stdin.readline

n = int(input())
seq = list(map(int, input().split()))

# dp[x] : seq[x]를 마지막 숫자로 가지는 가장 큰 증가 부분수열의 합
dp = [num for num in seq]
dp[0] = seq[0]

# 모든 인덱스 i에 대해, i보다 작은 값 j를 탐색해가면서 증가 부분수열의 합을 갱신해감
for i in range(1, n):
    for j in range(i):
        if seq[i] > seq[j]:
            dp[i] = max(dp[i], dp[j]+seq[i])

# dp 값 중 가장 큰 값이 가장 큰 증가 부분수열의 합임
print(max(dp))