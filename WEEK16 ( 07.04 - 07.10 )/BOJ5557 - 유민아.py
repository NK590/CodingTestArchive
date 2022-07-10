#다이나믹 프로그래밍 (작은 문제로 쪼갤수있음)

n = int(input())
list = list(map(int, input().split()))
# print(list)
dp = [[0 for _ in range(21)] for _ in range(n)] # n x 21 테이블 생성. 각 행에 계산한 결과(가능 횟수) 저장하여 마지막 행의 list[n-1] 에 저장된 값 출력
# print(dp)
dp[0][list[0]] = 1 #첫번째 행에 들어갈 값 초기화
idx = {list[0]} # 그 전에 행에서 더한 값들이 뭐인지 저장할 세트 --> 이 값에 + -를 구해줌
for i in range(1, n-1): #마지막 인덱스는계산안함
  tmp = set()
  # print('idx:', idx)
  for j in idx:
    if j + list[i] <= 20:
      dp[i][j+list[i]] += dp[i-1][j]
      tmp.add(j+list[i])
    if j-list[i] >= 0:
      dp[i][j-list[i]] += dp[i-1][j]
      tmp.add(j-list[i])
  idx = tmp

print(dp[n-2][list[n-1]])
