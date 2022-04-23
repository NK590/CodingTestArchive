n, k = map(int, input().split())

stuffList = []

for _ in range(n):
  weight, value = map(int, input().split())
  stuffList.append((weight, value))

d = [[0] * (k+1) for _ in range(n+1)]

for i in range(1, n+1):

  weight, value = stuffList[i-1]

  for j in range(1, k+1):
    if weight <= j:
      d[i][j] = max(value + d[i-1][j-weight], d[i-1][j])
    else:
      d[i][j] = d[i-1][j]

print(d[n][k])