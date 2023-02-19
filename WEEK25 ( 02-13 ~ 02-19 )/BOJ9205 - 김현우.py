import sys

input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    node_list = [list(map(int, input().split())) for _ in range(n+2)]
    grid = [[0 for _ in range(n+2)] for __ in range(n+2)]

    # 한 번에 갈 수 있는 거리 : 50 * 20 = 1000
    # 각각의 노드 사이 거리가 1000 이하면 0, 아니면 INF
    for i in range(n+2):
        for j in range(n+2):
            x1, y1 = node_list[i]
            x2, y2 = node_list[j]
            grid[i][j] = 0 if abs(x2-x1) + abs(y2-y1) <= 1000 else sys.maxsize

    # 플로이드 워셜
    for k in range(n+2):
        for i in range(n+2):
            for j in range(n+2):
                grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j])

    # 최종적으로 집에서 페스티벌 장소까지 거리값이 0이면 갈 수 있음, 아니면 갈 수 없음
    print("happy" if grid[0][-1] == 0 else "sad")