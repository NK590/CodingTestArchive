# https://www.acmicpc.net/problem/12100
# dfs + brute force 기법
# brute force: 난폭하게 모든 경우의 수를 다 탐색. 전체탐색방법으로는 순차탐색, dfs, bfs 등이 있다.

from copy import deepcopy

n = int(input())
graph = []
for i in range(n):
  graph.append(list(map(int, input().split())))

def move(board, dir):
  if dir == 0: # 동쪽
    for i in range(n):
      top = n -1
      for j in range(n-2, -1, -1):
        if board[i][j]:
          tmp = board[i][j]
          board[i][j] = 0
          if board[i][top] == 0:
            board[i][top] = tmp
          elif board[i][top] == tmp:
            board[i][top] = tmp * 2
            top -= 1
          else:
            top -= 1
            board[i][top] = tmp

  elif dir == 1:  # 서쪽
    for i in range(n):
      top = 0
      for j in range(1, n):
        if board[i][j]:
          tmp = board[i][j]
          board[i][j] = 0
          if board[i][top] == 0:
            board[i][top] = tmp
          elif board[i][top] == tmp:
            board[i][top] = tmp * 2
            top += 1
          else:
            top += 1
            board[i][top] = tmp

  elif dir == 2:  # 남쪽
    for j in range(n):
      top = n - 1
      for i in range(n - 2, -1, -1):
        if board[i][j]:
          tmp = board[i][j]
          board[i][j] = 0
          if board[top][j] == 0:
            board[top][j] = tmp
          elif board[top][j] == tmp:
            board[top][j] = tmp * 2
            top -= 1
          else:
            top -= 1
            board[top][j] = tmp

  else:
    for j in range(n):
      top = 0
      for i in range(1, n):
        if board[i][j]:
          tmp = board[i][j]
          board[i][j] = 0
          if board[top][j] == 0:
            board[top][j] = tmp
          elif board[top][j] == tmp:
            board[top][j] = tmp * 2
            top += 1
          else:
            top += 1
            board[top][j] = tmp

  return board

def dfs(board, cnt):
  global ans
  if cnt == 5:
    for i in range(n):
      for j in range(n):
        ans = max(ans, board[i][j]) #가장 큰 값 출력
    return
  
  #동서남북으로 움직임
  for i in range(4):
    tmp_board = move(deepcopy(board), i)
    dfs(tmp_board, cnt + 1) #재귀호출

ans = 0
dfs(graph, 0)
print(ans)