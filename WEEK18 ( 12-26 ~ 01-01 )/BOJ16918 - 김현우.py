import sys
from copy import deepcopy

input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

r, c, n = map(int, input().split())
grid = [list(input().rstrip()) for _ in range(r)]
timer_init = [[0 for _ in range(c)] for __ in range(r)]

for i in range(r):
    for j in range(c):
        if grid[i][j] == 'O':
            timer_init[i][j] = 3

timer_1 = deepcopy(timer_init)
for i in range(r):
    for j in range(c):
        if timer_1[i][j] == 3:
            timer_1[i][j] -= 1

timer_2 = deepcopy(timer_1)
for i in range(r):
    for j in range(c):
        if timer_2[i][j] == 0:
            timer_2[i][j] = 3
        else:
            timer_2[i][j] -= 1

timer_3 = deepcopy(timer_2)
bomb_list = []
for i in range(r):
    for j in range(c):
        timer_3[i][j] -= 1
for i in range(r):
    for j in range(c):
        if timer_3[i][j] == 0:
            bomb_list.append([i, j])
for bomb in bomb_list:
    x, y = bomb
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < r and 0 <= ny < c:
            timer_3[nx][ny] = 0

timer_4 = deepcopy(timer_3)
for i in range(r):
    for j in range(c):
        if timer_4[i][j] != 0:
            timer_4[i][j] -= 1
        else:
            timer_4[i][j] = 3

timer_5 = deepcopy(timer_4)
bomb_list = []
for i in range(r):
    for j in range(c):
        timer_5[i][j] -= 1
for i in range(r):
    for j in range(c):
        if timer_5[i][j] == 0:
            bomb_list.append([i, j])
for bomb in bomb_list:
    x, y = bomb
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < r and 0 <= ny < c:
            timer_5[nx][ny] = 0

for i in range(r):
    for j in range(c):
        if timer_1[i][j] == 0:
            timer_1[i][j] = '.'
        else:
            timer_1[i][j] = 'O'
        if timer_2[i][j] == 0:
            timer_2[i][j] = '.'
        else:
            timer_2[i][j] = 'O'
        if timer_3[i][j] == 0:
            timer_3[i][j] = '.'
        else:
            timer_3[i][j] = 'O'
        if timer_4[i][j] == 0:
            timer_4[i][j] = '.'
        else:
            timer_4[i][j] = 'O'
        if timer_5[i][j] == 0:
            timer_5[i][j] = '.'
        else:
            timer_5[i][j] = 'O'

# 아래 네 가지 경우만 반복되므로 분기처리 후 출력
if n == 1:
    for i in range(r):
        print(''.join(timer_1[i]))
elif n % 2 == 0:
    for i in range(r):
        print(''.join(timer_2[i]))
elif n % 4 == 3:
    for i in range(r):
        print(''.join(timer_3[i]))
elif n % 4 == 1:
    for i in range(r):
        print(''.join(timer_5[i]))
