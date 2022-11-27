import sys

input = sys.stdin.readline
sys.setrecursionlimit(100001)

# 사이클 탐지 DFS 탐색
def dfs(start):
    global cycleList
    # 시작점 방문 체크 후 사이클 시작점으로 설정
    visited[start] = True
    cycle.append(start)
    # 선택한 다음 사람 설정
    nextNum = students[start]

    # 이미 그 다음 사람 노드가 방문되었고 사이클 리스트 안에 들어가있을 시
    if visited[nextNum]:
        if nextNum in cycle:
            # 사이클이 완성되었음을 뜻하므로 해당 사람의 인덱스부터 한 사이클 분량의 인덱스를 cycleList에 추가
            cycleList += cycle[cycle.index(nextNum):]
            return
    else:
        # 그 외에는 계속 다음 사람을 탐색
        dfs(nextNum)

for _ in range(int(input())):
    n = int(input())
    students = [0] + list(map(int, input().split()))
    visited = [False for _ in range(n+1)]
    cycleList = []

    # 모든 사람에 대해 DFS로 사이클 여부 탐색
    for i in range(1, n+1):
        if not visited[i]:
            cycle = []
            dfs(i)
    
    # 최종적으로 cycleList에 들어있지 않은 사람 = 팀에 속하지 못한 사람
    # 전체 사람 수에서 해당 리스트의 길이를 빼주면 됨
    print(n - len(cycleList))
