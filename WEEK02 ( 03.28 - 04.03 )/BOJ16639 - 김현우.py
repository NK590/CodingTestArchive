import sys

input = sys.stdin.readline

# dp : dp 계산용 리스트
# operators : 연산자 리스트
# i, j : 인덱스 -> i ~ j 범위 내 탐색
def findMaxMinVal(dp, operators, i, j):
    temp = []
    for index in range(i, j):
        if operators[index] == '+':
            temp.append(dp[i][index][0] + dp[index+1][j][0])
            temp.append(dp[i][index][1] + dp[index+1][j][0])
            temp.append(dp[i][index][0] + dp[index+1][j][1])
            temp.append(dp[i][index][1] + dp[index+1][j][1])
        elif operators[index] == '-':
            temp.append(dp[i][index][0] - dp[index+1][j][0])
            temp.append(dp[i][index][1] - dp[index+1][j][0])
            temp.append(dp[i][index][0] - dp[index+1][j][1])
            temp.append(dp[i][index][1] - dp[index+1][j][1])
        else:
            temp.append(dp[i][index][0] * dp[index+1][j][0])
            temp.append(dp[i][index][1] * dp[index+1][j][0])
            temp.append(dp[i][index][0] * dp[index+1][j][1])
            temp.append(dp[i][index][1] * dp[index+1][j][1])
    return max(temp), min(temp)

n = int(input())
s = input().rstrip()

numList = []
operatorList = []

for i in range(n):
    if i % 2 == 1:
        operatorList.append(s[i])
    else:
        numList.append(int(s[i]))

lenNum = len(numList)

dp = [[[0, 0] for _ in range(lenNum)] for __ in range(lenNum)]

for searchRange in range(lenNum):
    for i in range(lenNum - searchRange):
        j = i + searchRange
        if i == j:
            dp[i][j][0] = numList[i]
            dp[i][j][1] = numList[i]
        else:
            maxVal, minVal = findMaxMinVal(dp, operatorList, i, j)
            dp[i][j][0] = maxVal
            dp[i][j][1] = minVal

print(max(dp[0][lenNum-1]))