# https://www.acmicpc.net/problem/12865
# 분할가능한 배낭채우기문제 : 욕심쟁이
# 분할불가능한 배낭채우기 문제(0-1 배낭문제) : 동적프로그래밍
# 이거는 무게순으로 계속 for문을 돌면 매우 비효율적이므로
# 0부터 max 무게까지 모든 무게만큼의 DP테이블을 만들어서 계산한다. 
# 재귀함수

#물품의 수 N과 버틸 수 있는 무게 K
n, k = map(int, input().split())
# print(n, k)

#물건정보 담을 리스트
weightList = []
valueList = []

#인덱스로 접근 가능하게
weightList.append(0)
valueList.append(0)

#리스트에 각각 추가
for _ in range(n):
  weight, value = map(int, input().split())
  weightList.append(weight)
  valueList.append(value)

#결과 저장할 dp테이블
d = [[0] * (k+1) for _ in range(n+1)]
# print(d)

for i in range(n+1):
  for j in range(k+1):
    
    #0번째 행, 열은 계산 안하고 0으로 셋팅
    if i == 0 or j == 0:
      d[i][j] = 0

    # 무게 더 들어갈 수 있을때
    elif weightList[i] <= j:
      # ((무게한도-넣으려는무게) 테이블에 저장된 거 + 새로운무게   VS   그 전꺼값)
      d[i][j] = max(valueList[i] + d[i-1][j-weightList[i]], d[i-1][j])

    #무게 더 들어갈 수 없을때는 그 전 value 그대로 
    else:
      d[i][j] = d[i-1][j]

print(d[n][k])
    
  



# #무게순으로 정렬
# stuffList.sort(reverse=True, key=lambda x:x[0])
# # for i in stuffList:
# #   print(i)

# possibleValueList = []

# def stuffing():
#   leftWeight = k
#   valueSum = 0
#   for i in stuffList:
#     weight, value = i
#     print(weight, value)
#     if weight <= leftWeight:
#       valueSum += value
#       leftWeight -= weight
#   possibleValueList.append(valueSum)

# stuffing()
# print(possibleValueList)

