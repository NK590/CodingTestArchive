import sys

input = sys.stdin.readline

n = int(input())
card_list = [0] + list(map(int, input().split()))

# dp[x] = 지불해야 하는 금액의 최댓값
dp = [0 for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, n+1):
        # 인덱스 범위 안에서 dp 갱신 -> 현재 인덱스에서의 dp값과 i-j의 dp값 + j번째 카드팩 가격 비교
        if i - j >= 0:
            dp[i] = max(dp[i], dp[i-j] + card_list[j])

print(dp[-1])
