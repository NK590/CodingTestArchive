import sys

sys.setrecursionlimit(100001)
input = sys.stdin.readline

MAX_LENGTH = 100001
MAX = sys.maxsize
answer = sys.maxsize

# 발을 움직일 때 드는 힘 함수
def move_feet(start, end):
    if start == end:
        return 1
    elif start == 0:
        return 2
    elif abs(start - end) == 1 or abs(start - end) == 3:
        return 3
    else:
        return 4

input_list = list(map(int, input().split()))
length = len(input_list)
# dp[x][y][z] : x번째로 왼발이 y번째 위치, 오른발이 z번째 위치에 올 때 드는 누적 힘
dp = [[[MAX for _ in range(5)] for __ in range(5)] for ___ in range(length+1)]
dp[0][0][0] = 0

# 입력해야 될 리스트를 이용해 순차적으로 dp 계산
for i in range(1, length):
    move = input_list[i-1]
    for left in range(5):
        for right in range(5):
            # 오른쪽 발, 왼쪽 발을 자유롭게 이동 가능하므로 모든 경우의 수를 생각해야 됨
            dp[i][move][right] = min(dp[i][move][right], dp[i-1][left][right] + move_feet(left, move))
            dp[i][left][move] = min(dp[i][left][move], dp[i-1][left][right] + move_feet(right, move))

# 최소값 갱신
for i in range(5):
    for j in range(5):
        answer = min(answer, dp[length-1][i][j])

print(answer)