import sys
graph = []
blank = []

for _ in range(9):
  graph.append(list(map(int, sys.stdin.readline().rstrip().split())))

for i in range(9):
  for j in range(9):
    if graph[i][j] == 0:
      blank.append((i, j))

def isOverwrapInRow(x, a):
  for i in range(9):
    if a == graph[x][i]:
      return True
  return False

def isOverwrapInCol(y, a):
  for i in range(9):
    if a == graph[i][y]:
      return True
  return False

def isOverwrapInBox(x, y, a):
  nx = x // 3 * 3
  ny = y // 3 * 3
  for i in range(3):
    for j in range(3):
      if a == graph[nx+i][ny+j]:
        return True
  return False

def dfs(idx):
  if idx == len(blank):
    for i in range(9):
      print(*graph[i])
    exit(0)
  
  for i in range(1, 10):
    x = blank[idx][0]
    y = blank[idx][1]
    if isOverwrapInRow(x, i)==False and isOverwrapInCol(y, i)==False and isOverwrapInBox(x, y, i)==False:
      graph[x][y] = i 
      dfs(idx + 1)
      graph[x][y] = 0

dfs(0)