import sys

# 정말 단순무식하게 가능한 테트로미노의 모양을 하나하나 만들어서 모조리 테스트를 함
# 아마 더 쉬운 방법이 있을듯...

input = sys.stdin.readline

n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

maxVal = 0

for i in range(n):
    for j in range(m-3):
        tempMaxVal = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + grid[i][j + 3]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

for i in range(n-3):
    for j in range(m):
        tempMaxVal = grid[i][j] + grid[i + 1][j] + grid[i + 2][j] + grid[i + 3][j]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

for i in range(n-1):
    for j in range(m-1):
        tempMaxVal = grid[i][j] + grid[i + 1][j] + grid[i][j + 1] + grid[i + 1][j + 1]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

for i in range(n-2):
    for j in range(m-1):
        tempMaxVal = grid[i][j] + grid[i + 1][j] + grid[i + 2][j] + grid[i + 2][j + 1]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

for i in range(n-2):
    for j in range(m-1):
        tempMaxVal = grid[i][j] + grid[i + 1][j] + grid[i + 2][j] + grid[i][j + 1]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

for i in range(n-2):
    for j in range(m-1):
        tempMaxVal = grid[i][j] + grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

for i in range(n-2):
    for j in range(m-1):
        tempMaxVal = grid[i + 2][j] + grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

for i in range(n-2):
    for j in range(m-1):
        tempMaxVal = grid[i][j] + grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 2][j + 1]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

for i in range(n-2):
    for j in range(m-1):
        tempMaxVal = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 1][j] + grid[i + 2][j]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

for i in range(n-2):
    for j in range(m-1):
        tempMaxVal = grid[i][j] + grid[i + 1][j] + grid[i + 2][j] + grid[i + 1][j + 1]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

for i in range(n-2):
    for j in range(m-1):
        tempMaxVal = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] + grid[i + 1][j]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

for i in range(n-1):
    for j in range(m-2):
        tempMaxVal = grid[i][j] + grid[i + 1][j] + grid[i][j + 1] + grid[i][j + 2]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

for i in range(n-1):
    for j in range(m-2):
        tempMaxVal = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + grid[i + 1][j + 2]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

for i in range(n-1):
    for j in range(m-2):
        tempMaxVal = grid[i][j] + grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

for i in range(n-1):
    for j in range(m-2):
        tempMaxVal = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] + grid[i][j + 2]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

for i in range(n-1):
    for j in range(m-2):
        tempMaxVal = grid[i][j] + grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 1][j + 2]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

for i in range(n-1):
    for j in range(m-2):
        tempMaxVal = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i][j + 1] + grid[i][j + 2]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

for i in range(n-1):
    for j in range(m-2):
        tempMaxVal = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + grid[i + 1][j + 1]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

for i in range(n-1):
    for j in range(m-2):
        tempMaxVal = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i][j + 1] + grid[i + 1][j + 2]
        if maxVal < tempMaxVal : maxVal = tempMaxVal

print(maxVal)