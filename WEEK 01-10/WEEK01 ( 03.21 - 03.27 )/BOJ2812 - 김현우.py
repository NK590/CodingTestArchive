# 스택을 이용한 풀이

import sys

input = sys.stdin.readline

n, k = map(int, input().split())
num_str = input().rstrip()
stack = []

for i in range(len(num_str)):
    # stack의 top이 num_str의 i번째 요소보다 작을 때
    # 1. stack이 비거나 2. k개를 전부 지웠거나 3. top이 num_str[i]보다 커질 때까지 pop
    while stack and k > 0 and stack[-1] < int(num_str[i]):
        stack.pop()
        k -= 1
    # stack의 top과 num_str[i]과의 비교가 끝났으면 push
    stack.append(int(num_str[i]))

# k개만큼 삭제하기 전에 위 반복문이 끝나는 경우가 있으므로,
# 이 경우에는 앞에서부터 len(stack) - k만큼 출력해야 됨
for i in range(len(stack) - k):
    print(stack[i], end = '')