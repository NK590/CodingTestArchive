import sys

input = sys.stdin.readline
MAX_LENGTH = 20
MIN_LENGTH = 0

n = int(input())
num_list = list(map(int, input().split()))

# dp[x][y] : num_list의 x번째 숫자까지 계산했을 때 그 결과가 y가 되는 경우의 수
dp = [[0 for _ in range(MAX_LENGTH + 1)] for __ in range(n+1)]
dp[1][num_list[0]] += 1 # num_list의 1번째 숫자만 고려하면 그 결과는 무조건 num_list[0]이고 경우의 수는 1

for i in range(1, n):
    for j in range(MAX_LENGTH + 1):
        # 경우의 수가 0이 아닐 때
        if dp[i][j] != 0:
            # 그 다음 수까지 포함하는 계산 결과가 20 이하일 때
            if j + num_list[i] <= MAX_LENGTH:
                dp[i+1][j+num_list[i]] += dp[i][j]
            # 0 이상일 때
            if j - num_list[i] >= MIN_LENGTH:
                dp[i+1][j-num_list[i]] += dp[i][j]

# n-1번째 수까지 계산했을 때 그 결과가 num_list의 마지막 수가 되는 경우의 수 출력
print(dp[n-1][num_list[-1]])