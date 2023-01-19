import sys

input = sys.stdin.readline

m, n, b = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

# 탐색해야 될 최저 높이, 최대 높이 설정
max_level = max([max(x) for x in grid])
min_level = min([min(x) for x in grid])

# [작업시간, 작업 후 블럭 높이]
ans = [sys.maxsize, 0]

# 모든 높이에 대해 완전탐색
for level in range(min_level, max_level+1):
    plus = 0 # 추가해야 되는 블럭 개수
    minus = 0 # 빼야 되는 블럭 개수
    for j in range(n):
        for k in range(n):
            if grid[j][k] > level:
                minus += grid[j][k] - level
            else:
                plus += level - grid[j][k]
    # 블록 개수가 오버되지 않을 때
    if b + minus >= plus:
        time = minus * 2 + plus
        if ans[0] >= time:
            ans = [time, level]

print(ans[0], ans[1])