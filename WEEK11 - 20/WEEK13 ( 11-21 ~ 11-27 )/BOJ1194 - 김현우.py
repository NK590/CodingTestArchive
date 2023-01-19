import sys
from collections import deque

input = sys.stdin.readline

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

# 비트 연산으로 해당 지점에서 키를 가지고 있는지 확인
def haveKey(cur_key, door):
    value = cur_key & (1 << (ord(door) - ord('A')))
    return True if value else False

def bfs(x, y):
    # 순서대로 x좌표, y좌표, 이동회수, A~F 키 비트값 체크
    q = deque([(x, y, 0, 0)])
    check = [[[False] * (1 << 6) for _ in range(50)] for _ in range(50)]
    check[x][y][0] = True

    while q:
        x, y, cnt, key = q.popleft()
        if board[x][y] == '1':
            return cnt
        for k in range(4):
            nx, ny = x + dx[k], y + dy[k]
            if 0 <= nx < N and 0 <= ny < M:
                # 해당 지점을 방문하지 않았을 때 -> 키 비트값도 변수에 들어감에 주의
                if not check[nx][ny][key]:
                    # 문/열쇠 칸이 아닌 빈칸으로 이동 시
                    if board[nx][ny] == '1' or board[nx][ny] == '.':
                        check[nx][ny][key] = True
                        q.append((nx, ny, cnt + 1, key))
                    # 열쇠 칸 이동 시
                    elif 'a' <= board[nx][ny] <= 'f':
                        # 키 비트값 갱신 후 이동 (키를 먹음)
                        tmp_key = key | (1 << (ord(board[nx][ny]) - ord('a')))
                        check[nx][ny][tmp_key] = True
                        q.append((nx, ny, cnt + 1, tmp_key))
                    # 문 칸 이동시
                    elif 'A' <= board[nx][ny] <= 'Z':
                        # 키를 가지고 있을 때만 지나갈 수 있음
                        if haveKey(key, board[nx][ny]):
                            check[nx][ny][key] = True
                            q.append((nx, ny, cnt + 1, key))
    return -1

N, M = map(int, input().split())
board = [list(map(str, input().rstrip())) for _ in range(N)]
for i in range(N):
    for j in range(M):
        if board[i][j] == '0':
            sx, sy = i, j
            board[i][j] = '.'
print(bfs(sx, sy))