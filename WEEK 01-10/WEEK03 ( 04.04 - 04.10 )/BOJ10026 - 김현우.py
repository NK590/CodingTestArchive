import sys
from collections import deque

n = int(sys.stdin.readline())
li = [list(sys.stdin.readline().rstrip()) for _ in range(n)]

chk = [[False for _ in range(n)] for __ in range(n)]
li2 = [[0 for _ in range(n)] for __ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
visited = deque([])

count_rg = 0
count_not_rg = 0

for i in range(n):
    for j in range(n):
        if li[i][j] != 'B':
            li2[i][j] = 1

for i in range(n):
    for j in range(n):
        if chk[i][j] == False:
            visited.append([i, j])
            color = li2[i][j]
            while visited:
                x, y = visited.popleft()
                chk[x][y] = True
                
                for k in range(4):
                    nx = x + dx[k]
                    ny = y + dy[k]
                    if 0 <= nx < n and 0 <= ny < n and [nx, ny] not in visited and chk[nx][ny] == False and li2[nx][ny] == color: 
                        visited.append([nx, ny])
            count_rg += 1

for i in range(n):
    for j in range(n):
        chk[i][j] = False

for i in range(n):
    for j in range(n):
        if li[i][j] == 'R':
            li2[i][j] = 2

for i in range(n):
    for j in range(n):
        if chk[i][j] == False:
            visited.append([i, j])
            color = li2[i][j]
            while visited:
                x, y = visited.popleft()
                chk[x][y] = True
                
                for k in range(4):
                    nx = x + dx[k]
                    ny = y + dy[k]
                    if 0 <= nx < n and 0 <= ny < n and [nx, ny] not in visited and chk[nx][ny] == False and li2[nx][ny] == color: 
                        visited.append([nx, ny])
            count_not_rg += 1

print(count_not_rg, count_rg, sep = ' ')