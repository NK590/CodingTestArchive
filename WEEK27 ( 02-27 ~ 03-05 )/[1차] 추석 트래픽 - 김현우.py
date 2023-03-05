# 주어진 시간 양식을 밀리초 단위로 파싱
def get_mili_time(time):
    hour = int(time[:2]) * 60 * 60 * 1000
    minute = int(time[3:5]) * 60 * 1000
    second = int(time[6:8]) * 1000
    mili = int(time[9:])
    return hour + minute + second + mili

# 주어진 처리시간을 밀리초 단위로 파싱
def get_start_mili_time(time, duration):
    duration_time = int(float(duration[:-1]) * 1000)
    return get_mili_time(time) - duration_time + 1

def solution(lines):
    answer = 0
    start_time = []
    end_time = []

    # 로그 문자열에서 각각 요청의 시작시간, 끝시간을 뽑아서 리스트에 append
    for entry in lines:
        time = entry.split(" ")
        start_time.append(get_start_mili_time(time[1], time[2]))
        end_time.append(get_mili_time(time[1]))

    # 시작시간 리스트, 끝시간 리스트를 순회하며 answer 값을 갱신
    for i in range(len(lines)):
        count = 0
        cur_end_time = end_time[i]
        for j in range(i, len(lines)):
            # 1초 간격 안에 있는 요청인지 확인
            if cur_end_time > start_time[j] - 1000:
                count += 1
        answer = max(answer, count)

    return answer