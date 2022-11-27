import sys
from copy import deepcopy

input = sys.stdin.readline

# 동서남북 방향에 따른 이동 픽셀
direction = ((0, 1), (-1, 0), (0, -1), (1, 0))

for _ in range(int(input())):
    cur_coord = [0, 0]              # 현재 좌표
    cur_direction = 0               # 현재 방향 (0 ~ 3)
    visited_point = []              # 방문한 죄표
    visited_point.append([0, 0])    # 방문한 좌표 초기값

    input_str = input().rstrip()

    for i in range(len(input_str)):
        # F : 전진
        if input_str[i] == 'F':
            cur_coord[0] += direction[cur_direction][0]
            cur_coord[1] += direction[cur_direction][1]
            visited_point.append(deepcopy(cur_coord))   # 그냥 append하면 기존 cur_coord 요소가 영향을 받아서 deepcopy 후 append
        # B : 후진
        elif input_str[i] == 'B':
            cur_coord[0] -= direction[cur_direction][0]
            cur_coord[1] -= direction[cur_direction][1]
            visited_point.append(deepcopy(cur_coord))
        # L : 좌향 좌
        elif input_str[i] == 'L':
            cur_direction = (cur_direction + 1) % 4
        # R : 우향 우
        elif input_str[i] == 'R':
            cur_direction = (cur_direction + 3) % 4
    
    # 최대 x값, 최소 x값을 뽑기 위해 정렬
    visited_point.sort()
    max_x = visited_point[-1][0]
    min_x = visited_point[0][0]

    # 최대 y값, 최소 y값을 뽑기 위해 정렬
    visited_point.sort(key=lambda x : x[1])
    max_y = visited_point[-1][1]
    min_y = visited_point[0][1]

    # 직사각형 넓이 구하기
    print((max_x - min_x) * (max_y - min_y))