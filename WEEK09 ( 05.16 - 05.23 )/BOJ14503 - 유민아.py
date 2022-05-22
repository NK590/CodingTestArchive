# https://www.acmicpc.net/problem/14503
# 로봇청소기
# 구현문제

import sys
input = sys.stdin.readline

# 세로칸수, 가로칸수
n, m = map(int, input().split())

#로봇청소기 위치 (r,c), 바라보는 방향 d : 0 북쪽 1 동쪽 2 남쪽 3 서쪽
r, c, d = map(int, input().split())

# 장소의 상태가 빈칸이면 0, 벽이면 1
graph = [list(map(int, input().split())) for _ in range(n)]
# print(graph)

# 바라보는 방향 d : 북쪽0 동쪽1 남쪽2 서쪽3에 맞게 인덱스 셋팅
# 근데 로봇청소기는 저 숫자대로 안돌고 시계 반대방향으로 돈다.
nx, ny = [-1,0,1,0], [0,1,0,-1]

# 방문여부
# 회전후 갈곳이 이미 방문한 곳이라면 패쓰
visited = [[0] * m for _ in range(n)]

# 처음 시작하는 곳 방문 처리
visited[r][c] = 1
count = 1

while True:

  # 해당 위치에서 이동해서 청소했는지 여부 -> while문 시작할때마다 0으로 리셋
  # 회전 다 했는데도(for 문 다 돌음) 청소를 한번도 못했다면(isTurnAndClean = 0) 후진하거나 종료해야함
  isTurnAndClean= 0

  # 방향개수4개만큼 반복. 
  for _ in range(4):

    # 방향 셋팅
    # (d+3)%4는 변수nx의 인덱스는 북동남서 순인데 회전은 북서남동이라 바꿔주기 위한것
    d = (d+3)%4
    # 그 방향대로 회전
    dx, dy = nx[d]+r, ny[d]+c

    # 위치 범위 내에 있고, 빈곳이고, 방문 안했을 경우
    if 0 <= dx < n and 0 <= dy < m and graph[dx][dy] == 0 and visited[dx][dy] == 0:
      # 청소기 위치 이동한다
      r,c = dx, dy
      # 청소한다.
      count += 1
      # 방문처리한다
      visited[dx][dy] = 1
      # 해당위치에서 청소했다고 표시. 
      isTurnAndClean += 1
      break #for문 종료
  
  # 회전 다 했는데 청소한 곳이 없음
  if isTurnAndClean == 0:

    # 후진했을 때 뒤가 벽이면 종료
    # 후진은 보고있는 방향은 그대로이기 때문에 d를 바꾸면 안됨!
    if graph[r-nx[d]][c-ny[d]] == 1:
      print(count)
      break  # while문 종료
    # 아니면 후진한다.
    else :
      r, c = r-nx[d], c-ny[d]

  