import sys

input = sys.stdin.readline

n, k = map(int, input().split())
graphList = [list(map(int, input().split())) for _ in range(n)]

minTime = sys.maxsize
visitedPath = [False for _ in range(n)]
visitedPath[k] = True


for via in range(n):
    for start in range(n):
        for end in range(n):
            graphList[start][end] = min(graphList[start][end], graphList[start][via]+graphList[via][end])

def backtrack(start, count, time):
    global minTime

    if count == n:
        minTime = min(minTime, time)
        return

    for nextNode in range(n):
        if not visitedPath[nextNode]:
            visitedPath[nextNode] = True
            backtrack(nextNode, count+1, time+graphList[start][nextNode])
            visitedPath[nextNode] = False

backtrack(k, 1, 0)

print(minTime)
