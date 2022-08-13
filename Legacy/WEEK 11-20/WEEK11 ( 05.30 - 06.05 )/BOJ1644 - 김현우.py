import sys

input = sys.stdin.readline

MAX_NUM = 4000001 # 입력으로 주어지는 최대 숫자
count = 0 # 가능한 소수의 연속합 경우의 수
start = 0 # 시작 포인터
end = 1 # 끝 포인터

# 소수 여부 체크용 리스트
primeNumCheck = [True for _ in range(MAX_NUM)]

# 에라토스테네스의 체
for i in range(2, int(MAX_NUM ** 0.5)):
    if primeNumCheck[i]:
        for j in range(2*i, MAX_NUM, i):
            primeNumCheck[j] = False

primeNumList = []

# 소수 리스트 계산
for i in range(2, MAX_NUM):
    if primeNumCheck[i]:
        primeNumList.append(i)

# 소수 연속합 리스트 계산
primeSum = [0 for _ in range(len(primeNumList) + 1)]
for i in range(len(primeNumList)):
    primeSum[i+1] = primeSum[i] + primeNumList[i]

n = int(input())

# 투 포인터 알고리즘
while start < len(primeSum):
    # 연속합이 n일 때 -> count += 1 후 시작 포인터를 증가
    if primeSum[end] - primeSum[start] == n:
        count += 1
        start += 1
    # 연속합이 n보다 클 때 -> 시작 포인터를 증가
    elif primeSum[end] - primeSum[start] > n:
        start += 1
    # 연속합이 n보다 작을 때 -> 끝 포인터가 끝 지점까지 도착 하지 않았으면 끝 포인터를 증가,
    # 끝 포인터가 마지막 지점에 도달했으면 시작 포인터를 증가
    else:
        if end < len(primeSum) - 1:
            end += 1
        else:
            start += 1

print(count)