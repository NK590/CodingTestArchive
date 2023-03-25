def solution(record):
    answer = []
    # 출력되는 메세지에는 최종 닉네임만 들어감 -> 닉네임을 딕셔너리로 관리하면서 업데이트
    nick_map = {}
    enter_msg = '님이 들어왔습니다.'
    leave_msg = '님이 나갔습니다.'

    for log in record:
        temp_li = list(log.split())
        if len(temp_li) == 3:
            cmd, user_id, nick = temp_li
            nick_map[user_id] = nick
            if cmd == 'Enter':
                answer.append([user_id, enter_msg])
        else:
            cmd, user_id = temp_li
            answer.append([user_id, leave_msg])

    return [nick_map[entry[0]] + entry[1] for entry in answer]