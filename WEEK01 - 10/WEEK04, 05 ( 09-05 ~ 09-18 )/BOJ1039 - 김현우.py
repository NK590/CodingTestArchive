import sys
from collections import deque

input = sys.stdin.readline

def bfs():
    # return 값의 초기값을 -1로 잡아줌 -> bfs 탐색이 불가능하고 갱신이 안 되었을 때 이 값 출력
    ans = -1
    while q:
        num, count = q.popleft()
        # k번 탐색을 했으면 ans 갱신 후 그 다음 원소 탐색
        if count == k:
            ans = max(ans, int(''.join(num)))
            continue
        # 임의로 바꿀 i, j 인덱스에 대해 탐색
        for i in range(len_n):
            for j in range(i+1, len_n):
                # 만약 맨 처음 자리 인덱스 숫자와 '0'인 숫자를 바꾸려고 한다면
                # -> 첫 자리가 0이 되므로 문제 조건에 의해 탐색 불가 -> continue
                if i == 0 and num[j] == '0':
                    continue

                # i번째, j번째 원소 swap
                temp = num[i]
                num[i] = num[j]
                num[j] = temp

                # visited 체크
                num_int = int(''.join(num))
                if not visited[num_int][count+1]:
                    visited[num_int][count+1] = True
                    # 여기서 큐에 다음 탐색값을 넣을 때 num.copy()로 깊은 복사를 해야 정상 작동함
                    q.append([num.copy(), count+1])

                # i번째, j번째 원소 원래대로 되돌려놓기
                temp = num[i]
                num[i] = num[j]
                num[j] = temp
    return ans

n, k = input().split()

len_n = len(n)
k = int(k)
# 가능한 한 모든 수, 모든 탐색 횟수에 맞춰서 visited 리스트를 설정함
# visited[x][y] : 숫자 x를 y번째 탐색에 방문하였는지
visited = [[False for _ in range(11)] for __ in range(1000001)]

# bfs용 큐 초기값 : [초기 숫자 list, 탐색횟수(0)]
q = deque([[list(n), 0]])
visited[int(n)][0] = True

result = bfs()
print(result)