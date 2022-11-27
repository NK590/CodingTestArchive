import sys
from collections import deque

input = sys.stdin.readline
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs():
    queue = deque([graph])
    visited[graph] = 0

    # bfs 탐색 시작
    while queue:
        target = queue.popleft()
        # 완전히 정돈되었을 때 그때가지 이동한 횟수를 return
        if target == "123456780":
            return visited[target]

        # 비어있는 칸의 위치를 찾아서 그 좌표를 지정
        idx = target.find("0")
        x = idx // 3
        y = idx % 3

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < 3 and 0 <= ny < 3:
                # 상하좌우 좌표가 grid 안에 있을 시 0을 기준으로 지정된 방향으로 두 숫자 swap
                n = nx * 3 + ny
                list_target = list(target)
                list_target[idx], list_target[n] = list_target[n], list_target[idx]
                new_target = "".join(list_target)

                # 아직 visited 딕셔너리에 해당 new_target 값이 없을 시 = 아직 방문하지 않은 퍼즐 상태일 시
                # queue에 append
                if not visited.get(new_target):
                    visited[new_target] = visited[target] + 1
                    queue.append(new_target)
    # bfs 탐색이 끝날 때까지 정렬이 안 되었을 때 -> -1 출력
    return -1

# graph : 입력 숫자를 각각 일렬로 입력받은 문자열
graph = ''.join([''.join(list(input().split())) for _ in range(3)])
# 메모리 제한으로 visited 체크를 위해 일반적인 리스트가 아닌 해시 함수를 이용해야 함
# 여기서는 딕셔너리를 이용
visited = dict()

result = bfs()
print(result)