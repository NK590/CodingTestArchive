import sys

input = sys.stdin.readline

### 주의점 : 문제에서 주어진 상하 방향과 실제 풀이에서 상하 방향이 반대임

dx = (1, 0, -1, 0)
dy = (0, -1, 0, 1)
dir = { 'N' : 0, 'W' : 1, 'S' : 2, 'E' : 3 } # 방향 지정
robot_dir = dict() # 각 로봇의 방향 지정

a, b = map(int, input().split())
grid = [[0 for _ in range(a)] for __ in range(b)]
n, m = map(int, input().split())

for i in range(n):
    x, y, d = input().split()
    grid[int(y)-1][int(x)-1] = i+1
    robot_dir[i+1] = dir[d]

# 여기까지 각각 로봇의 위치와 방향 입력받기, 여기부터 로봇 명령 입력받기

for i in range(m):
    num, com, repeat = input().split()
    num, repeat = int(num), int(repeat)
    for j in range(b):
        for k in range(a):
            if grid[j][k] == num:
                xx, yy = j, k
    # 전진
    if com == 'F':
        for _ in range(repeat):
            nx = xx + dx[robot_dir[num]]
            ny = yy + dy[robot_dir[num]]
            # grid 범위를 초과할 경우 벽에 충돌
            if 0 > nx or nx >= b or 0 > ny or ny >= a:
                print("Robot " + str(num) + " crashes into the wall")
                exit(0)
            # 다음 이동 칸에 다른 로봇이 있을 때 로봇에 충돌
            elif grid[nx][ny] != 0:
                print("Robot " + str(num) + " crashes into robot " + str(grid[nx][ny]))
                exit(0)
            else:
                grid[xx][yy], grid[nx][ny] = grid[nx][ny], grid[xx][yy]
                xx, yy = nx, ny
    # 좌향 좌
    elif com == 'L':
        robot_dir[num] = (robot_dir[num] + repeat) % 4
    # 우향 우
    elif com == 'R':
        robot_dir[num] = (robot_dir[num] + 3 * repeat) % 4

print("OK")