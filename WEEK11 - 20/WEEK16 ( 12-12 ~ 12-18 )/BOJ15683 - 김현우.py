import sys

input = sys.stdin.readline
LIGHT = 7 # 감시 여부 중복을 처리하기 위해 0~6보다 큰 수인 7을 기본 단위로 계산
ans = sys.maxsize

# index 방향으로 감시하는 함수
def enlight(index, x, y):
    if index == 0:
        for i in range(x-1, -1, -1):
            if grid[i][y] % LIGHT == 0:
                grid[i][y] += LIGHT
            elif grid[i][y] % LIGHT != 6:
                continue
            else:
                break
    elif index == 1:
        for i in range(y+1, m):
            if grid[x][i] % LIGHT == 0:
                grid[x][i] += LIGHT
            elif grid[x][i] % LIGHT != 6:
                continue
            else:
                break
    elif index == 2:
        for i in range(x+1, n):
            if grid[i][y] % LIGHT == 0:
                grid[i][y] += LIGHT
            elif grid[i][y] % LIGHT != 6:
                continue
            else:
                break
    elif index == 3:
        for i in range(y-1, -1, -1):
            if grid[x][i] % LIGHT == 0:
                grid[x][i] += LIGHT
            elif grid[x][i] % LIGHT != 6:
                continue
            else:
                break

# index 방향 감시 여부 삭제 함수
def dislight(index, x, y):
    if index == 0:
        for i in range(x-1, -1, -1):
            if grid[i][y] % LIGHT == 0:
                grid[i][y] -= LIGHT
            elif grid[i][y] % LIGHT != 6:
                continue
            else:
                break
    elif index == 1:
        for i in range(y+1, m):
            if grid[x][i] % LIGHT == 0:
                grid[x][i] -= LIGHT
            elif grid[x][i] % LIGHT != 6:
                continue
            else:
                break
    elif index == 2:
        for i in range(x+1, n):
            if grid[i][y] % LIGHT == 0:
                grid[i][y] -= LIGHT
            elif grid[i][y] % LIGHT != 6:
                continue
            else:
                break
    elif index == 3:
        for i in range(y-1, -1, -1):
            if grid[x][i] % LIGHT == 0:
                grid[x][i] -= LIGHT
            elif grid[x][i] % LIGHT != 6:
                continue
            else:
                break

# 각각의 CCTV가 감시하는 방향의 모든 경우의 수 백트래킹
def backtrack(index):
    global ans
    if index == observer_num:
        count = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 0:
                    count += 1
        ans = min(ans, count)
        return
    num, x, y = observer_list[index]
    if num == 1:
        for i in range(4):
            enlight(i, x, y)
            backtrack(index+1)
            dislight(i, x, y)
    elif num == 2:
        for i in range(2):
            enlight(i, x, y)
            enlight(i+2, x, y)
            backtrack(index+1)
            dislight(i, x, y)
            dislight(i+2, x, y)
    elif num == 3:
        for i in range(4):
            enlight(i, x, y)
            enlight((i+1)%4, x, y)
            backtrack(index+1)
            dislight(i, x, y)
            dislight((i+1)%4, x, y)
    elif num == 4:
        for i in range(4):
            enlight(i, x, y)
            enlight((i+1)%4, x, y)
            enlight((i+2)%4, x, y)
            backtrack(index+1)
            dislight(i, x, y)
            dislight((i+1)%4, x, y)
            dislight((i+2)%4, x, y)
    elif num == 5:
        for i in range(4):
            enlight(i, x, y)
        backtrack(index+1)
        for i in range(4):
            dislight(i, x, y)
    

n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

# CCTV 정보 입력 (CCTV 번호, x좌표, y좌표)
observer_list = []
for i in range(n):
    for j in range(m):
        if grid[i][j] not in (0, 6):
            observer_list.append([grid[i][j], i, j])
observer_num = len(observer_list)

backtrack(0)

print(ans)