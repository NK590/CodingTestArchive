import sys

input = sys.stdin.readline

h, w = map(int, input().split())
heights = list(map(int, input().split()))
waters = 0

# 기준점 기준 왼쪽 최대 높이, 오른쪽 최대 높이 계산
# -> 기준점의 높이가 min(왼쪽 최대 높이, 오른쪽 최대 높이) 보다 낮을 시에는 그 높이차이만큼 물이 쌓임
for i in range(1, w-1):
    left_max = max(heights[:i])
    right_max = max(heights[i+1:])

    if heights[i] < min(left_max, right_max):
        waters += min(left_max, right_max) - heights[i]

print(waters)