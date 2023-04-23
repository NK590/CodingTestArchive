def check(answer):
    for x, y, stuff in answer:
        # 기둥일 때
        if stuff == 0:
            # 바닥에 있던지, 밑에 기둥이 있던지, 밑에 보가 깔려있던지
            if y == 0 or [x, y - 1, 0] in answer or [x - 1, y, 1] in answer or [x, y, 1] in answer:
                continue
            else:
                return False
        # 보일 때
        elif stuff == 1:
            # 양쪽 끝 밑에 기둥이 달려있던지, 아니면 양 옆으로 보가 깔려있던지
            if [x, y - 1, 0] in answer or [x + 1, y - 1, 0] in answer or (
                    [x - 1, y, 1] in answer and [x + 1, y, 1] in answer):
                continue
            else:
                return False
    return True


def solution(n, build_frame):
    answer = []

    for build in build_frame:
        # x좌표, y좌표, 구조물종류, 연산종류
        x, y, stuff, operation = build

        # 설치
        if operation == 1:
            # 일단 answer에 넣어보고, 실패하면 빼기
            answer.append([x, y, stuff])
            if not check(answer):
                answer.remove([x, y, stuff])
        # 삭제
        elif operation == 0:
            # 일단 answer에서 빼보고, 성공하면 다시 넣기
            answer.remove([x, y, stuff])
            if not check(answer):
                answer.append([x, y, stuff])

    answer.sort()

    return answer