import sys
from collections import deque

input = sys.stdin.readline

# num번째 톱니바퀴 기준 오른쪽 톱니바퀴들 돌리기
def rotate_r(num, direction):
    if num > 3 or wheels[num-1][2] == wheels[num][6]:
        return
    if wheels[num-1][2] != wheels[num][6]:
        rotate_r(num + 1, -direction)
        wheels[num].rotate(direction)

# num번째 톱니바퀴 기준 왼쪽 톱니바퀴들 돌리기
def rotate_l(num, direction):
    if num < 0 or wheels[num][2] == wheels[num + 1][6]:
        return
    if wheels[num][2] != wheels[num + 1][6]:
        rotate_l(num - 1, -direction)
        wheels[num].rotate(direction)

# 톱니바퀴 정보 입력
wheels = [deque(list(map(int, input().rstrip()))) for _ in range(4)]

for _ in range(int(input())):
    num, direction = map(int, input().split())
    num = num - 1 # 인덱스 계산을 위해 1을 빼줌
    rotate_r(num + 1, -direction) # 오른쪽 톱니바퀴들 돌리고
    rotate_l(num - 1, -direction) # 왼쪽 톱니바퀴들 돌리고
    wheels[num].rotate(direction) # 자기 자신도 돌리고

ans = sum([wheels[i][0] << i for i in range(4)])

print(ans)