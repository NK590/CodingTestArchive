def solution(n, t, m, timetable):
    answer = 0
    # 크루 도착시간을 분으로 환산 후 정렬
    time_list = [int(time[:2]) * 60 + int(time[3:]) for time in timetable]
    time_list.sort()

    # 버스 도착시간을 분으로 환산
    bus_time = [540 + t * i for i in range(n)]
    # 크루의 인덱스
    index = 0

    for bus in bus_time:
        count = 0
        # 버스 도착시간과 크루들의 도착시간을 비교해가며 도착시간 갱신
        while count < m and index < len(time_list) and time_list[index] <= bus:
            index += 1
            count += 1
        answer = bus if count < m else time_list[index - 1] - 1

    # 정답을 양식에 맞게 환산
    return str(answer // 60).zfill(2) + ":" + str(answer % 60).zfill(2)