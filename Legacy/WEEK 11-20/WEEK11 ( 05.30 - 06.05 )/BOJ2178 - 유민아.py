# https://www.acmicpc.net/problem/2178

# 최소의 칸수: ==> bfs (deque)

from collections import deque

n, m = map(int, input().split())

graph = []

for _ in range(n):
  graph.append(list(map(int, input())))

#print(graph)

dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]

def bfs(x, y):
  queue = deque()
  queue.append((x, y))

  while queue:
    x, y = queue.popleft()

    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]

      # 범위에서 벗어나지 않고 벽이 아님
      if 0 <= nx < n and 0 <= ny < m and graph[nx][ny] != 0:
        # 한번도 가보지 않은 길. 가보면 계속 +1이 추가되므로 다시 가지 않게 가보지않은 길에만 적용
        if graph[nx][ny] == 1:
          graph[nx][ny] = graph[x][y] + 1
          queue.append((nx, ny))
        else : 
          continue
      else:
        continue

  return graph[n-1][m-1]

print(bfs(0, 0))