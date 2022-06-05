n = int(input())

d = [0] * 31
d[2] = 3

for i in range(4, n+1, 2):
  d[i] =  2 + 3*d[i-2] + sum(d[:i-2])*2 

print(d[n])