# // https://www.acmicpc.net/problem/5014
from collections import deque
from math import floor
import sys

input = sys.stdin.readline
f, s, g, u, d = map(int, input().split())

def bfs(f, s, g, u, d):
  queue = deque([[s, 0]]) #[현재 위치, 이동횟수]
  visited = [s]

  while queue:
    current, count = queue.popleft()
    if current == g: #현재 위치가 목표 층이랑 같을떄
      return count
    if current + u <= f and current + u not in visited:
      queue.append([current + u, count + 1])
      visited.append(current + u)
    if current - d >= 1 and current - d not in visited:
      queue.append([current - d, count + 1])
      visited.append(current - d)
  return "use the stairs"

print(bfs(f, s, g, u, d))
