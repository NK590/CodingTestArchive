import sys

input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

X_LENGTH = 5
Y_LENGTH = 9
DIRECTION = 4

def minSearch(x, y, pin, move):
    global minPin
    global minMove
    
    if pin <= minPin:
        if pin == minPin:
            if minPin != 0:
                minMove = min(move, minMove)
        else:
            minPin = pin
            minMove = move
    
    for i in range(DIRECTION):
        nx = x + dx[i]
        ny = y + dy[i]
        
        if nx < 0 or ny < 0 or nx >= X_LENGTH or ny >= Y_LENGTH:
            continue
        if grid[nx][ny] != 'o':
            continue
        
        nnx = nx + dx[i]
        nny = ny + dy[i]
        
        if nnx < 0 or nny < 0 or nnx >= X_LENGTH or nny >= Y_LENGTH:
            continue
        if grid[nnx][nny] != '.':
            continue
        
        grid[x][y] = '.'
        grid[nx][ny] = '.'
        grid[nnx][nny] = 'o'

        for j in range(X_LENGTH):
            for k in range(Y_LENGTH):
                if grid[j][k] == 'o':
                    minSearch(j, k, pin-1, move+1)
        
        grid[x][y] = 'o'
        grid[nx][ny] = 'o'
        grid[nnx][nny] = '.'

n = int(input())

for i in range(n):
    
    pin = 0
    minPin = 0
    minMove = 0

    if i != n-1:
        grid = [list(input().rstrip()) for _ in range(X_LENGTH+1)]
        grid.pop()
    else:
        grid = [list(input().rstrip()) for _ in range(X_LENGTH)]
        
    for j in range(X_LENGTH):
        for k in range(Y_LENGTH):
            if grid[j][k] == 'o':
                pin += 1
    minPin = pin
    
    for j in range(X_LENGTH):
        for k in range(Y_LENGTH):
            if grid[j][k] == 'o':
                minSearch(j, k, pin, 0)
    
    print(minPin, minMove)