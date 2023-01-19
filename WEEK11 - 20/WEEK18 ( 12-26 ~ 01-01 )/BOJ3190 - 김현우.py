import sys
from collections import deque

input = sys.stdin.readline

# 순서대로 동 남 서 북
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
# 초기 방향은 동쪽
direction = 0
# 시간
time = 0
# 뱀 초기 위치
snake = deque([[0, 0]])
# 방향전환 명령
commands = deque()

# 입력부
n = int(input())
grid = [[0 for _ in range(n)] for __ in range(n)]
for _ in range(int(input())):
    x, y = map(int, input().split())
    grid[x - 1][y - 1] = 1
for _ in range(int(input())):
    t, dir = input().split()
    commands.append((int(t), dir))

# 초기값 설정
grid[0][0] = 2
t, dir = commands.popleft()

# 더이상 게임 진행이 불가능할 때까지 반복
while True:
    # 명령어 해당 시간이 되었을 때 명령어 처리
    if t == time:
        if dir == 'L':
            direction = (direction + 3) % 4
        elif dir == 'D':
            direction = (direction + 1) % 4
        if len(commands) != 0:
            t, dir = commands.popleft()
    
    # 다음 머리가 움직일 위치
    x, y = snake[-1]
    nx, ny = x + dx[direction], y + dy[direction]
    
    # 그리드 밖으로 나갔을 때, 자기 몸에 부딪혔을 때 게임 종료
    if 0 > nx or nx >= n or 0 > ny or ny >= n:
        break
    elif grid[nx][ny] == 2:
        break
    
    # 뱀 이동 및 사과먹기 처리
    snake.append([nx, ny])
    if grid[nx][ny] == 1:
        grid[nx][ny] = 2
    elif grid[nx][ny] == 0:
        grid[nx][ny] = 2
        x, y = snake.popleft()
        grid[x][y] = 0

    time += 1

print(time + 1)