import sys

input = sys.stdin.readline

n = int(input())
signal = input().rstrip()

# 시그널을 5행으로 분리
signal_list = [signal[(n//5)*i:(n//5)*i+n//5] for i in range(5)]

ans = []
index = 0

# 5행으로 분리된 시그널을 index를 통해 왼쪽부터 탐색
while index < n//5:
    # 현재 index 열
    cur_col = ''.join([signal_list[i][index] for i in range(5)])

    if cur_col == '.....':
        index += 1
        continue

    if cur_col == '#####':
        if index == n//5 - 1:
            ans.append('1')
            index += 1
            continue

    # 현재 index 다음열
    cur_col_next = ''.join([signal_list[i][index+1] for i in range(5)])

    if cur_col_next == '.....':
        ans.append('1')
        index += 2
        continue

    # 현재 인덱스 다다음열
    cur_col_next_next = ''.join([signal_list[i][index+2] for i in range(5)])

    if cur_col == '#####':
        if cur_col_next == '#...#' and cur_col_next_next == '#####':
            ans.append('0')
        elif cur_col_next == '#.#.#' and cur_col_next_next == '#.###':
            ans.append('6')
        elif cur_col_next == '#.#.#' and cur_col_next_next == '#####':
            ans.append('8')
    elif cur_col == '###.#':
        if cur_col_next == '#.#.#' and cur_col_next_next == '#.###':
            ans.append('5')
        if cur_col_next == '#.#.#' and cur_col_next_next == '#####':
            ans.append('9')
    elif cur_col == '#.###' and cur_col_next == '#.#.#' and cur_col_next_next == '###.#':
        ans.append('2')
    elif cur_col == '#.#.#' and cur_col_next == '#.#.#' and cur_col_next_next == '#####':
        ans.append('3')
    elif cur_col == '###..' and cur_col_next == '..#..' and cur_col_next_next == '#####':
        ans.append('4')
    elif cur_col == '#....' and cur_col_next == '#....' and cur_col_next_next == '#####':
        ans.append('7')

    index += 3

print(''.join(ans))