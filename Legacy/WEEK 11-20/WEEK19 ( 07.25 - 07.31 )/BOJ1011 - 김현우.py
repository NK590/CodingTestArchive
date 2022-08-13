import sys

input = sys.stdin.readline

# 일종의 그리디 알고리즘
# 최초 속력 1광년/회 부터 계속 속력을 증가시켜서 최고속력 찍고 다시 최저속력 1광년/회 까지 감속하는 게 최적해

for _ in range(int(input())):
    start, end = map(int, input().split())
    total_travel = end - start
    max_travel = 1      # count회 작동으로 이동할 수 있는 최고 거리
    count = 1           # 장치를 작동할 횟수
    while True:         # 장치 작동 횟수별 가능한 최대 이동 거리를 계산하며 실제 이동해야 될 거리와 반복
        if total_travel <= max_travel:
            print(count)
            break
        else:
            max_travel += (count // 2) + 1
            count += 1