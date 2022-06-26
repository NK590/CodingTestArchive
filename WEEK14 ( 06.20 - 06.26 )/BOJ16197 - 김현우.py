import sys
from collections import deque

input = sys.stdin.readline
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

def bfs(): # bfs 탐색 함수 -> return값이 최소 이동 횟수
    while coinPos:
        x1, y1, x2, y2, count = coinPos.popleft()

        if count >= 10: # 10회 이상 탐색 시 -1 return
            return -1

        for i in range(4): # 상하좌우 4방향 탐색
            nx1 = x1 + dx[i]
            ny1 = y1 + dy[i]
            nx2 = x2 + dx[i]
            ny2 = y2 + dy[i]

            if 0 <= nx1 < n and 0 <= ny1 < m and 0 <= nx2 < n and 0 <= ny2 < m: # 두 동전이 모두 떨어지지 않았을 때
                if grid[nx1][ny1] == '#': # 1번째 동전이 벽에 부딪혔을 때
                    nx1, ny1 = x1, y1
                if grid[nx2][ny2] == '#': # 2번째 동전이 벽에 부딪혔을 때
                    nx2, ny2 = x2, y2
                coinPos.append([nx1, ny1, nx2, ny2, count + 1])
            elif 0 <= nx1 < n and 0 <= ny1 < m: # 2번째 동전이 떨어졌을 때
                return count + 1
            elif 0 <= nx2 < n and 0 <= ny2 < m: # 1번째 동전이 떨어졌을 때
                return count + 1
            else: # 동전이 둘 다 떨어졌을 때 -> while 문 탈출 (return -1)
                continue

    return -1

n, m = map(int, input().split())

grid = [list(input().strip()) for _ in range(n)]
coinPos = deque()
coinPosTemp = []

for i in range(n):
    for j in range(m):
        if grid[i][j] == 'o':
            coinPosTemp.append(i)
            coinPosTemp.append(j)
coinPosTemp.append(0)
coinPos.append(coinPosTemp) # coinPos에 담기는 변수 순서 : [x1, y1, x2, y2, 이동횟수]

print(bfs())