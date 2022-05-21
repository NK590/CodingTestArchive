# https://www.acmicpc.net/problem/1697
# 숨바꼭질

# 가장 짧은, 가장 빠른과 같은 것 -> BFS
# 파이썬에서 queue는 deque를 사용
# queue는 한쪽으로만 입력 가능, 반대쪽으로만 출력 가능
# deque는 양쪽으로 입출력 가능

from collections import deque

# 수빈, 동생 위치
n, k = map(int, input().split())

# 최대위치값
max_position = 100000

#동생을 찾는 시간을 저장한 테이블
timeTable = [0] * (max_position + 1)

def bfs():

  # 큐에 현재 수빈이 위치 추가
  queue = deque()
  queue.append(n)

  while queue:

    x = queue.popleft()
    if x == k:
      print(timeTable[x])
      break

    for nx in (x+1, x-1, x*2):
      # print(timeTable[nx])
      # 이동한 위치가 범위 내에 있고 아직 방문하지 않았다면 
      if 0 <= nx <= max_position and not timeTable[nx]:
        # 이동시간 저장
        timeTable[nx] = timeTable[x] + 1
        # 큐에 추가
        queue.append(nx)

bfs()