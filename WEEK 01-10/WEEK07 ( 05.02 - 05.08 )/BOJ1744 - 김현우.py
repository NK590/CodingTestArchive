import sys

input = sys.stdin.readline

n = int(input())
numList = [int(input()) for _ in range(n)]
numList.sort()

# 음수~0 배열, 양수 배열, 최대합 선언
numListMinus = []
numListPlus = []
maxSum = 0

# 주어진 수들을 정렬 후 음수~0 / 양수 두 그룹으로 분류
for i in range(n):
    if numList[i] <= 0:
        numListMinus.append([numList[i], False])
    else:
        numListPlus.append([numList[i], False])

# 계산 편의를 위해 양수 그룹은 내림차순 정렬
numListPlus.sort(reverse=True)

# 제일 작은 두 음수끼리 묶어서 곱해나가며 더하기
i = 0
while True:
    try:
        maxSum += numListMinus[i][0] * numListMinus[i + 1][0]
        numListMinus[i][1] = True
        numListMinus[i + 1][1] = True
        i += 2
    except IndexError:
        break

# 제일 큰 두 양수끼리 묶어서 곱해나가며 더하기
i = 0
while True:
    try:
        if numListPlus[i][0] >= 2 and numListPlus[i + 1][0] >= 2:
            maxSum += numListPlus[i][0] * numListPlus[i + 1][0]
            numListPlus[i][1] = True
            numListPlus[i + 1][1] = True
            i += 2
        # 단, 해당 숫자가 1인 경우는 두 수를 묶어 곱하는 것보다 각자 더하는 것이 이득
        else:
            maxSum += numListPlus[i][0]
            numListPlus[i][1] = True
            i += 1
    except IndexError:
        break

# 위 과정에서 선택되지 않은 남은 수들을 마저 더하기
numList = [x for x in numListMinus + numListPlus if x[1] == False]
maxSum += sum([x[0] for x in numList])

print(maxSum)