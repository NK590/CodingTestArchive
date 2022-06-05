import sys
from collections import deque

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

n, m = map(int, sys.stdin.readline().split())
maze = [list(map(int, list(sys.stdin.readline().rstrip()))) for _ in range(n)]
minPath = [[0 for _ in range(m)] for __ in range(n)] # 각 칸별 최단 이동 거리를 저장해줄 리스트

# 초기값 설정
visited = deque([[0, 0]])
minPath[0][0] = 1

# BFS 탐색
while visited:
    x, y = visited.popleft()
    
    # 도착 지점에 첫 번째로 도달했으면 그 때가지 이동한 거리값 출력 후 종료
    if x == n-1 and y == m-1:
        print(minPath[x][y])
        break
    
    # 상하좌우 4방향 탐색
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < n and 0 <= ny < m:
            if minPath[nx][ny] == 0 and maze[nx][ny] == 1:
                minPath[nx][ny] = minPath[x][y] + 1
                visited.append([nx,ny])