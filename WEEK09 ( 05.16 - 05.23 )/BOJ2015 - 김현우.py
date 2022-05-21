# 이 문제는 도저히 풀이법이 안 떠올라서 인터넷 검색해서 풀이법 찾아봤습니다.
# 아직도 100% 이해가 가진 않았습니다.

import sys
from collections import defaultdict

input = sys.stdin.readline

n, k = map(int, input().split())
numList = list(map(int, input().split()))
count = 0 # 합이 정확히 k인 부분합 카운트

# 부분합 리스트 선언
sumList = [0 for _ in range(n+1)]
for i in range(1, n+1):
    sumList[i] = sumList[i-1] + numList[i-1]

# 임의의 키에 대해 초기값이 0인 딕셔너리(해쉬맵) 선언
checkDict = defaultdict(int)

# 계산한 부분합에 대해 아래를 처리함
for i in range(1, n+1):
    if sumList[i] == k: # i번째 인덱스까지 부분합 값이 k와 일치할 시 count++
        count += 1
    count += checkDict[sumList[i] - k] # i번째 인덱스까지의 부분합 - k
    checkDict[sumList[i]] += 1 # i까지의 부분합 갱신

print(count)