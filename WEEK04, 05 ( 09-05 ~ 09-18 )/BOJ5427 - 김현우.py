import sys
from collections import deque

input = sys.stdin.readline
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# 불과 상근이가 전파되는 bfs 탐색
def bfs():
    global person, fire
    # bfs 탐색 시작
    while person:
        temp = deque()
        # 상근이 이동 시작
        while person:
            x, y = person.popleft()
            # 상근이가 무사히 빠져나갔을 때 해당 grid값 return
            if (x == h - 1 or y == w - 1 or x == 0 or y == 0) and grid[x][y] != "*":
                return grid[x][y]
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < h and 0 <= ny < w and grid[nx][ny] == "." and grid[x][y] != "*":
                    grid[nx][ny] = grid[x][y] + 1
                    temp.append([nx, ny])
        person = temp
        temp = deque()
        # 불 전파 시작
        while fire:
            x, y = fire.popleft()
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < h and 0 <= ny < w and not fire_visit[nx][ny] and grid[nx][ny] != "#":
                    grid[nx][ny] = "*"
                    fire_visit[nx][ny] = True
                    temp.append([nx, ny])
        fire = temp

t = int(input())

for i in range(t):
    w, h = map(int, input().split())
    grid, fire, person = [], deque(), deque()
    fire_visit = [[False for _ in range(w)] for __ in range(h)]

    for j in range(h):
        a = list(input().strip())
        grid.append(a)
        for k in range(w):
            if a[k] == "@":
                grid[j][k] = 0
                person.append([j, k])
            elif a[k] == "*":
                fire.append([j, k])
                fire_visit[j][k] = True

    result = bfs()
    # bfs의 return 값이 있을 때 -> result 값 + 1
    # return 값이 없을 때 (None값) -> 탈출이 불가능하므로 IMPOSSIBLE 출력
    print(result + 1 if result != None else "IMPOSSIBLE")