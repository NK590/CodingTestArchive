import sys

input = sys.stdin.readline

n,m,x,y,k = map(int,input().split())

board = []
for _ in range(n):
    board.append(list(map(int,input().split())))

cmds = list(map(int,input().split()))

dice_a = [0,0,0,0,0,0,0]
dice_b = [0,0,0,0,0,0,0]

def process(dice_b,x,y):
    # 윗면 출력
    print(dice_b[1])
    # 바닥면 수 작업
    board_num = board[x][y]

    if board_num == 0:
        board[x][y] = dice_b[6]
    else:
        dice_b[6] = board_num
        board[x][y] = 0

    return dice_b

for cmd in cmds:
    #남
    if cmd == 4:
        # 주사위 이동
        nx = x+1
        # 범위 밖이면 무시
        if 0 <= nx and nx <= n-1:
            x = nx
            #새로운 주사위 전개도
            dice_b[2]=dice_a[6]
            dice_b[1]=dice_a[2]
            dice_b[5]=dice_a[1]
            dice_b[6]=dice_a[5]
            dice_b[3]=dice_a[3]
            dice_b[4]=dice_a[4]

            dice_a = process(dice_b,x,y)

            dice_b = [0,0,0,0,0,0,0]
        else:
            continue
    #북
    if cmd == 3:
        # 주사위 이동
        nx = x-1
        # 범위 밖이면 무시
        if 0 <= nx and nx <= n-1:
            x = nx
            #새로운 주사위 전개도
            dice_b[6]=dice_a[2]
            dice_b[2]=dice_a[1]
            dice_b[1]=dice_a[5]
            dice_b[5]=dice_a[6]
            dice_b[3]=dice_a[3]
            dice_b[4]=dice_a[4]

            dice_a = process(dice_b,x,y)

            dice_b = [0,0,0,0,0,0,0]
        else:
            continue
    # 서
    if cmd == 2:
        # 주사위 이동
        ny = y - 1
        # 범위 밖이면 무시
        if 0 <= ny and ny <= m-1:
            y = ny
            # 새로운 주사위 전개도
            dice_b[6] = dice_a[4]
            dice_b[1] = dice_a[3]
            dice_b[4] = dice_a[1]
            dice_b[3] = dice_a[6]
            dice_b[5] = dice_a[5]
            dice_b[2]=dice_a[2]

            dice_a = process(dice_b,x,y)

            dice_b = [0, 0, 0, 0, 0, 0, 0]
        else:
            continue
    # 동
    if cmd == 1:
        # 주사위 이동
        ny = y + 1
        # 범위 밖이면 무시
        if 0 <= ny and ny <= m-1:
            y = ny
            # 새로운 주사위 전개도
            dice_b[4] = dice_a[6]
            dice_b[3] = dice_a[1]
            dice_b[1] = dice_a[4]
            dice_b[6] = dice_a[3]
            dice_b[5] = dice_a[5]
            dice_b[2]=dice_a[2]

            dice_a = process(dice_b,x,y)

            dice_b = [0, 0, 0, 0, 0, 0, 0]
        else:
            continue
