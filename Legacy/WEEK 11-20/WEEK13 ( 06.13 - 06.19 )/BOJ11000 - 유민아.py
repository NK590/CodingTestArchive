# https://www.acmicpc.net/problem/11000
# 작업 스케줄링 문제 (욕심쟁이)
# heapq 사용
# 강의가 겹치는지 확인 -> 강의 끝나는 시간을 heapq에 넣어서 겹치면 계속 heap에 추가. 근데 heap내부적으로는 강의 끝나는 시간이 빠른 순서대로 적용되므로 --> 새로 강의 추가하려 할때마다 heap[0](가장 빨리 끝나는 강의)랑 비교할 수 있다!!! 그래서 그 둘이 안겹치면heap[0]을 빼고 신규강의의 끝나는 시간을 추가한다.(그럼 또 내부적으로 가장 빨리 끝나는 순으로 정렬된다.) 
# 최종적으로 heap에 들어간 개수가 필요한 강의실의 최소 개수

# 참고: 
# deque: 선입선출. bfs에서 사용
# from collections import deque
# q=deque()
# q.append('l')
# q.popleft()

# heapq: 큐에 넣으면 내부에서 작은순으로 정렬하여 값을 저장. -> heap[0]는 가장 작은 값. 
# 최소힙, 최대힙
# 다익스트라, 최소값이나 최대값을 빨리 찾아야 할 때 사용
# from heapq import heappush, heappop, heapify
# q=[]
# heappush(q, 1)
# heappop(q)
# heapify(arr)

import sys
import heapq
input = sys.stdin.readline

n = int(input())

list = [list(map(int, input().split())) for _ in range(n)]

# print(list)
#먼저 사용한 순, 먼저 나온 순으로 정렬
list.sort()
# print(list)

endTimeQueue = []
heapq.heappush(endTimeQueue, list[0][1]) # 먼저 들어간 강의가 끝난 시간 넣음

for i in range(1, n):
  #넣으려는 강의의 시작시간과 힙에 들어간 강의(가장 빨리 끝나는 강의)의 끝나는 시간이 겹치면
  if list[i][0] < endTimeQueue[0]:
    #힙에 넣는다(필요한 강의실 1개 추가) (-> 힙큐 내부적으로 먼저 끝나는 강의 순으로 정렬시킨다.)
    heapq.heappush(endTimeQueue, list[i][1])
  # 겹치지 않으면 같은 강의실 이어 쓰고, 끝나는 시간만 업뎃한다.(힙 교체)
  else:
    # 가장 빨리 끝나는 강의의 끝나는 시간을 버리고
    heapq.heappop(endTimeQueue)
    # 새로운 강의의 끝나는 시간을 넣는다. (->힙큐 내부적으로 먼저 끝나는 강의 순으로 정렬시킨다.)
    heapq.heappush(endTimeQueue, list[i][1])
  # print(endTimeQueue)

print(len(endTimeQueue))
	
