import sys

input = sys.stdin.readline

### 끝나는 시간이 제일 빠른 회의들을 먼저 배정하면 최대 개수 ###

n = int(input())
time_list = [list(map(int, input().split())) for _ in range(n)]

# 입력받은 회의시간 리스트를 (끝나는 시간 오름차순) -> (시작하는 시간 오름차순) 순으로 정렬
time_list.sort(key = lambda x : (x[1], x[0]))

# 초기값
count = 1
end_time = time_list[0][1]

# 정렬된 회의 시간 리스트를 돌면서 기존 회의 끝나는 시간 <= 다음 회의 시작시간일 때 갱신
# 이미 끝나는 시간에 맞춰 오름차순 정렬이 되어있으므로 최적값임
for i in range(1, len(time_list)):
    if time_list[i][0] >= end_time:
        count += 1
        end_time = time_list[i][1]

print(count)