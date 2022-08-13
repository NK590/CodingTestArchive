# https://www.acmicpc.net/problem/1915

#  dp문제
# 원리: n*n 테이블이 모두 1로 채워져 있다면
# n*n 번째 자리에는 n이 저장되게 하면됨
# (x,x)번째 값은 (x-1, x-1)과 (x-1, x)와 (x, x-1) 세개 중 가장 작은값 +1 로 하면 됨
# 그러면 dp테이블에서 가장 큰 n의 제곱이 정답값

import sys
input = sys.stdin.readline

n, m = map(int, input().split())

graph = []

for _ in range(n):
  graph.append(list(map(int, input().strip())))

# print(graph)

dp = [[0]*m for _ in range(n)]

# 결과값
maxSize = 0

for i in range(n):
  for j in range(m):
    if i ==0 or j == 0: #왼쪽위부터 시작해서 (x,x)를 구하는 것이므로 x-1이 없으므로 원래값으로 초기화
      dp[i][j] = graph[i][j]
    elif graph[i][j] == 0: #0으로는 정사각형을 만들 수 없으므로 0으로 초기화
      dp[i][j] = 0
    else:
      dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
    maxSize = max(maxSize, dp[i][j])


print(maxSize * maxSize)




