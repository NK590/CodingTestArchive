import sys

input = sys.stdin.readline
answer = 0

homeworks = [list(map(int, input().split())) for _ in range(int(input()))]
visited = [False for _ in range(1001)]

# 마감일을 무시하고 과제의 점수별로 내림차순 정렬
homeworks.sort(key = lambda x : x[1], reverse = True)

# 점수별로 내림차순 정렬된 과제를 전부 탐색 -> 높은 점수 과제부터 탐색
for day, point in homeworks:
    day_count = day
    # 높은 점수 과제부터 과제가 가능한 날짜를 탐색
    while day_count > 0 and visited[day_count]:
        day_count -= 1
    # 과제가 가능한 날이 없으면 패스
    if day_count == 0:
        continue
    else:
        # 해당 날짜에 끝내는 과제를 갱신하고 그 과제의 점수 갱신
        visited[day_count] = True
        answer += point

print(answer)