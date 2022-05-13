# 내리막길
# https://www.acmicpc.net/problem/1520
# 맨 왼쪽 위에서 맨 오른쪽 아래로 이동하는 경로의 수는?
# 현재 위치보다 낮은 지점으로만 간다.
# 최단거리 아니고 상하좌우 모두 이동 가능.
# 경로 개수 찾기 --> dfs + dp
# 임의의 점까지 가는 방법 + 그 이후의 방법 = 총 경우의수 ===> 부분최적해로 나눌 수 있다.

import sys
input = sys.stdin.readline

# 세로크기 m, 가로크기 n
m, n = map(int, input().split())

# 각 경로의 높이가 저장된 2차원 배열
heightList = [list(map(int, input().split())) for _ in range(m)]

# 2차원 dp테이블
# 안가본 길 vs 가본길 구분해서 가본 길이라면 중복해서 구하지 않도록 초기값은 모두 안가본 길 -1로 셋팅
dp = [[-1] * n for _ in range(m)]

# 이동 방향 옵션
dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]


def dfs(x, y): #x좌표 y좌표
  
  # 이동가능한 경로의 수
  # 함수에 좌표가 들어오면 일단 dp[x][y] = 0으로 셋팅해서 가본길로 표기되도록 변수 마련
  possiblePathCount = 0

  # 도착지점에 도달하면 1을 리턴 -> 이게 백트랙킹되면서 1 반환 1반환 1반환 ...-> 해서 한가지의 경로가 된다. 그리고 가장 마지막에 있는 for문으로 돌아감 - (갈 수 있는 다른 방향이 있다면 1+1 해서 2가 됨 (갈수있는 경로가 2개가 됨..) 이런 식으로 bottom-up
  if x == m-1 and y == n -1:
    return 1
  
  # 이미 가본 길이면 해당 위치에서 종료위치까지의 가능경로개수를 바로 리턴 
  # (여기서 리턴 안하고 밑에 for문으로 내려간다면 경우의 수가 중복된다)
  if dp[x][y] != -1:
    return dp[x][y]

  # 이동방향 셋팅 - 상하좌우 모두 가능
  for i in range(4):
    nx, ny = x + dx[i], y + dy[i] #이동한 좌표
    # 그래프 범위 안에 있고 나아갈 좌표가 현재 좌표보다 높이값이 작아야 진전이 가능
    if 0 <= nx < m and 0 <= ny < n and heightList[nx][ny] < heightList[x][y] :
      # dp테이블의 현재 좌표테이블에 기존 경로개수와 합친다.
      possiblePathCount += dfs(nx, ny)
  
  dp[x][y] = possiblePathCount #상하좌우 돌려서 나오는 모든 경우의 수를 저장
  return dp[x][y] # 백트랙킹해서 최종적으로 dp[0][0]의 값을 리턴하게 된다.

print(dfs(0, 0))
