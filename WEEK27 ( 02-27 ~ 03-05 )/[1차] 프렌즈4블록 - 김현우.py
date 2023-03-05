from collections import deque

def solution(m, n, board):
    answer = 0
    check = set()
    board = [list(row) for row in board]

    # board의 변화가 없을 때까지 반복
    while True:
        # 터트릴 블록 체크
        for i in range(m - 1):
            for j in range(n - 1):
                if board[i][j] == board[i + 1][j] == board[i][j + 1] == board[i + 1][j + 1] != 'X':
                    check.add((i, j))
                    check.add((i, j + 1))
                    check.add((i + 1, j))
                    check.add((i + 1, j + 1))

        # 터트릴 블록이 있을 시
        if check:
            # 터트린 칸을 'X'로 체크
            for i, j in check:
                board[i][j] = 'X'
            answer += len(check)
            # 'X' 칸 위로 밀어내기
            for j in range(n):
                q = deque()
                for i in range(m - 1, -1, -1):
                    if board[i][j] == 'X':
                        q.append((i, j))
                    else:
                        if q:
                            x, y = q.popleft()
                            board[x][y] = board[i][j]
                            board[i][j] = 'X'
                            q.append((i, j))
            check.clear()
        # 터트릴 블록이 없으면 더이상 board 변화 없음 -> 반복문 종료
        else:
            break

    return answer