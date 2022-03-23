import sys

input = sys.stdin.readline

dice = [0 for _ in range(6)]

# dice : 주사위의 각 면의 숫자를 나타내는 배열
# direction : 이동 방향 쿼리
# cur_position : 주사위의 현재 위치
def roll_dice(dice, direction, cur_position):
    i, j = cur_position

    if direction == 1:
        if j + 1 < m:
            dice[0], dice[2], dice[5], dice[3] = dice[3], dice[0], dice[2], dice[5]
            if map_list[i][j+1] == 0:
                map_list[i][j+1] = dice[5]
            else:
                dice[5] = map_list[i][j+1]
                map_list[i][j+1] = 0
            cur_position[1] += 1
            print(dice[0])
    
    elif direction == 2:
        if j - 1 >= 0:
            dice[0], dice[2], dice[5], dice[3] = dice[2], dice[5], dice[3], dice[0]
            if map_list[i][j-1] == 0:
                map_list[i][j-1] = dice[5]
            else:
                dice[5] = map_list[i][j-1]
                map_list[i][j-1] = 0
            cur_position[1] -= 1
            print(dice[0])
    
    elif direction == 3:
        if i - 1 >= 0:
            dice[0], dice[1], dice[5], dice[4] = dice[4], dice[0], dice[1], dice[5]
            if map_list[i-1][j] == 0:
                map_list[i-1][j] = dice[5]
            else:
                dice[5] = map_list[i-1][j]
                map_list[i-1][j] = 0
            cur_position[0] -= 1
            print(dice[0])
    
    elif direction == 4:
        if i + 1 < n:
            dice[0], dice[1], dice[5], dice[4] = dice[1], dice[5], dice[4], dice[0]
            if map_list[i+1][j] == 0:
                map_list[i+1][j] = dice[5]
            else:
                dice[5] = map_list[i+1][j]
                map_list[i+1][j] = 0
            cur_position[0] += 1
            print(dice[0])

n, m, x, y, k = map(int, input().split())
cur_position = [x, y]
map_list = [list(map(int, input().split())) for _ in range(n)]
command_list = list(map(int, input().split()))

for command in command_list:
    roll_dice(dice, command, cur_position)