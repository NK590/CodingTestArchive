import sys

input = sys.stdin.readline

n, k = map(int, input().split())
knapsack = [[0 for _ in range(k+1)] for __ in range(n+1)]

stuff = [[0, 0]]
for _ in range(n):
    stuff.append(list(map(int, input().split())))

for i in range(1, n+1):
    for j in range(1, k+1):
        weight, value = stuff[i]
        if j < weight:
            knapsack[i][j] = knapsack[i-1][j]
        else:
            knapsack[i][j] = max(value + knapsack[i-1][j-weight], knapsack[i-1][j])

print(knapsack[n][k])