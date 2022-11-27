import sys
from heapq import heappop, heappush, heapify

input = sys.stdin.readline

### 카드 뭉치들 중 제일 숫자가 작은 것부터 합쳐나가야 최소 비교회수 ###

n = int(input())
cards = [int(input()) for _ in range(n)]

answer = 0

# 카드 묶음이 딱 하나만 있을 때는 이미 카드 묶음이 정렬되어 있는 것을 알고 있으므로
# 한 번도 비교할 필요가 없음 -> 0 출력 후 종료
if n == 1:
    print(answer)
    exit(0)

# 우선순위 큐(힙)을 이용한 최소값 계산
# 카드 묶음 중에서 제일 작은 장수 묶음끼리 합쳐나가야 됨
heapify(cards)

while len(cards) > 1:
    x = heappop(cards)
    y = heappop(cards)
    answer += (x + y)
    heappush(cards, (x + y))

print(answer)