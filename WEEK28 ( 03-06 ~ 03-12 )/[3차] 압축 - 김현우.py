def solution(msg):
    # { A : 1, B : 2, .... } 딕셔너리
    dictionary = {chr(i + 64): i for i in range(1, 27)}
    dic_index = 27
    answer = []
    msg = msg + "." # 인덱스
    start, end = 0, 1 # 탐색할 부분 문자열의 시작 인덱스, 끝 인덱스

    # 주어진 문자열 끝까지 탐색
    while end < len(msg):
        # 딕셔너리에 부분 문자열이 없을 때까지 끝 인덱스 늘리기
        while msg[start:end] in dictionary:
            end += 1
        # 없는 문자열은 딕셔너리에 추가 후 answer에 색인 번호 추가
        dictionary[msg[start:end]] = dic_index
        dic_index += 1
        answer.append(dictionary[msg[start:end - 1]])
        # 인덱스 초기화
        start, end = end - 1, end

    return answer