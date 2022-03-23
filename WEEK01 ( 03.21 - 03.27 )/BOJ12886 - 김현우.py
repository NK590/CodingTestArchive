import sys
from collections import deque

input = sys.stdin.readline

# 돌을 아무리 옮겨도 세 그룹의 돌 개수 총합이 일정한 것에 착안하면, 
# 두 그룹의 돌의 개수만 알아도 나머지 한 그룹의 돌의 개수를 알 수 있음
# -> 2차원 boolean 리스트로 모든 돌 그룹 상태의 방문 여부 체크 가능

visited = [[False for _ in range(1501)] for __ in range(1501)]
# 세 그룹 돌 개수 총합이 최대 1500이므로, 하나의 그룹의 돌 개수도 1500까지 될 가능성이 있음
# -> 1500 * 1500 크기의 리스트가 필요

a, b, c = map(int, input().split())
sum_stone = a + b + c
deq = deque([[a, b]])

# 돌을 옮기는 bfs 탐색
while deq:
    x, y = deq.popleft()
    z = sum_stone - x - y
    
    if x == y and y == z:
        print(1)
        exit(0)
    
    if x < y:
        if not visited[2*x][y-x]:
            visited[2*x][y-x] = True
            deq.append([2*x, y-x])
    elif y < x:
        if not visited[x-y][2*y]:
            visited[x-y][2*y] = True
            deq.append([x-y, 2*y])
    
    if y < z:
        if not visited[x][2*y]:
            visited[x][2*y] = True
            deq.append([x, 2*y])
    elif z < y:
        if not visited[x][y-z]:
            visited[x][y-z] = True
            deq.append([x, y-z])
    
    if z < x:
        if not visited[x-z][y]:
            visited[x-z][y] = True
            deq.append([x-z, y])
    elif x < z:
        if not visited[2*x][y]:
            visited[2*x][y] = True
            deq.append([2*x, y])

print(0)