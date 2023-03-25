from itertools import combinations

def solution(relation):
    possible_list = []
    actual_list = []
    column_len = len(relation[0])
    column_index = [i for i in range(column_len)]
    # 우선 가능한 경우의 수 인덱스를 전부 저장
    for i in range(1, column_len + 1):
        possible_list.extend(combinations(column_index, i))

    for entry in possible_list:
        # 인덱스 조합 리스트에서 하나씩 뽑아서 실제 후보키 만들기
        temp = [tuple([item[key] for key in entry]) for item in relation]

        # 유일성 조건
        if len(relation) == len(set(temp)):
            chk = True
            for x in actual_list:
                # 최소성 조건
                if set(x).issubset(set(entry)):
                    chk = False
                    break
            if chk:
                actual_list.append(entry)

    return len(actual_list)