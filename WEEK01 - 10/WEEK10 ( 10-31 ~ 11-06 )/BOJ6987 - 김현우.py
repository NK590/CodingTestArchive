import sys
from itertools import combinations

input = sys.stdin.readline

answer_list = []
# combinations로 가능한 대진표 인덱스 모두 뽑기
num_list = list(combinations([i for i in range(6)], 2))

def backtrack(index):
    global answer
    # 모든 대진표를 탐색 완료했을 떄 answer 갱신
    # 입력받은 li의 엔트리가 전부 0인지 체크
    if index == 15:
        answer = 1
        for subset in li:
            if subset != [0, 0, 0]:
                answer = 0
                break
        return
    
    round_x, round_y = num_list[index]
    # 승, 무, 패 탐색 -> 이미 입력받은 li에서 승무패 결과에 따라 하나씩 빼면서 재귀탐색
    for index_x, index_y in ((0, 2), (1, 1), (2, 0)):
        if li[round_x][index_x] > 0 and li[round_y][index_y] > 0:
            li[round_x][index_x] -= 1
            li[round_y][index_y] -= 1
            backtrack(index + 1)
            li[round_x][index_x] += 1
            li[round_y][index_y] += 1

for num in range(4):
    input_num = list(map(int, input().split()))
    # 다루기 용이하게 2중 리스트 형식으로 끊어서 입력받기
    li = [input_num[i:i+3] for i in range(0, 16, 3)]
    # answer값을 backtrack으로 갱신 후 그 값을 answer_list에 append
    answer = 0
    backtrack(0)
    answer_list.append(answer)

print(*answer_list)

    