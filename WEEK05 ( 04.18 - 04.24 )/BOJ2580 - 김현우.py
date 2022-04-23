import sys

input = sys.stdin.readline
sys.setrecursionlimit(10000)

MAX_LENGTH = 9
SQUARE_LENGTH = 3

def in_square(num, x, y):
    for i in range(SQUARE_LENGTH):
        for j in range(SQUARE_LENGTH):
            if grid[SQUARE_LENGTH*(x//SQUARE_LENGTH) + i][SQUARE_LENGTH*(y//SQUARE_LENGTH) + j] == num:
                return True
    return False

def in_x_axis(num, y):
    for i in range(MAX_LENGTH):
        if grid[i][y] == num:
            return True
    return False

def in_y_axis(num, x):
    for i in range(MAX_LENGTH):
        if grid[x][i] == num:
            return True
    return False

def backtrack(empty_count):
    if empty_count == len(empty_entries):
        for i in range(MAX_LENGTH):
            print(*grid[i])
        exit(0)

    for i in range(1, MAX_LENGTH+1):
        x, y = empty_entries[empty_count]

        if not in_square(i, x, y) and not in_y_axis(i, x) and not in_x_axis(i, y):
            grid[x][y] = i
            backtrack(empty_count+1)
            grid[x][y] = 0

grid = [list(map(int, input().split())) for _ in range(MAX_LENGTH)]
empty_entries = []

for i in range(MAX_LENGTH):
    for j in range(MAX_LENGTH):
        if grid[i][j] == 0:
            empty_entries.append([i, j])

backtrack(0)