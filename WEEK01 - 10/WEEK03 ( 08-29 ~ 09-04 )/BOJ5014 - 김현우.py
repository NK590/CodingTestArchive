import sys
from collections import deque

input = sys.stdin.readline

f, s, g, u, d = map(int, input().split())
visited = [False for _ in range(f+1)]

# deque 초기 시작점 : [s층, 버튼을 누른 횟수(0)]
q = deque([[s, 0]])
visited[s] = True

while q:
    startFloor, count = q.popleft()
    # 현재 큐의 시작점이 도착점(g층)이면 저장된 count 값을 출력 후 프로그램 종료
    if startFloor == g:
        print(count)
        exit(0)
    # u 버튼을 누를 시
    if startFloor + u <= f and not visited[startFloor + u]:
        q.append([startFloor + u, count + 1])
        visited[startFloor + u] = True
    # d 버튼을 누를 시
    if startFloor - d > 0 and not visited[startFloor - d]:
        q.append([startFloor - d, count + 1])
        visited[startFloor - d] = True

# bfs 탐색을 완료할 때까지 g층까지 도달하지 못한다면 엘리베이터로 갈 수 없는 층
print('use the stairs')