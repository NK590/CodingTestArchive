import sys
from heapq import * # 우선순위큐(힙) 를 이용

input = sys.stdin.readline

n = int(input())
classes = [list(map(int, input().split())) for _ in range(n)]

classes.sort()
heap = []
heappush(heap, classes[0][1]) # 제일 먼저 시작해서 제일 먼저 끝난 강의의 끝난 시간을 초기값으로 입력

for i in range(1, n):
    if classes[i][0] < heap[0]: # 수업 시작 시간이 전 강의실들 중 가장 빠르게 수업이 끝나는 시간보다 이르면
        heappush(heap, classes[i][1]) # 새 강의실 파기
    else:
        heappop(heap) # 그 외의 경우 -> 수업 끝나는 시간 갱신
        heappush(heap, classes[i][1])

print(len(heap)) # heap에 최종적으로 남아있는 원소의 개수 = 총 강의실 수