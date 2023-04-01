def solution(m, musicinfos):

    # 샾(#)이 붙은 음은 인덱스 처리가 어려움으로 묶어서 소문자로 전부 치환
    m = m.replace('C#', 'c')
    m = m.replace('D#', 'd')
    m = m.replace('F#', 'f')
    m = m.replace('G#', 'g')
    m = m.replace('A#', 'a')

    melodies = []

    # musicinfos에서 각각 노래의 총 플레이 시간과 악보를 통해 곡별 전체 반복된 악보를 구함
    for music in musicinfos:
        start, end, name, melody = music.split(',')
        duration = (int(end[:2]) - int(start[:2])) * 60 + (int(end[3:]) - int(start[3:]))

        melody = melody.replace('C#', 'c')
        melody = melody.replace('D#', 'd')
        melody = melody.replace('F#', 'f')
        melody = melody.replace('G#', 'g')
        melody = melody.replace('A#', 'a')

        whole_melody = melody * (duration // len(melody)) + melody[:(duration % len(melody))]
        melodies.append((name, duration, whole_melody))

    # 기억한 멜로디와 일치하는 곡이 있으면 그 곡 정보를 answer 리스트에 저장
    answer = []
    index = 0
    for name, duration, melody in melodies:
        if melody.find(m) != -1:
            answer.append((-duration, index, name))
        index += 1

    # 일치하는 멜로디 -> 재생시간이 제일 긴 음악 -> 먼저 입력된 음악 순서에 맞게 오름차순 정렬 후 맨 앞 결과 출력
    answer.sort()
    if answer:
        return answer[0][2]
    else:
        return '(None)'