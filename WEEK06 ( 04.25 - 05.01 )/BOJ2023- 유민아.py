import sys
import math

N = int(sys.stdin.readline())

list = [[2,3,5,7],[],[],[],[],[],[],[],]
start_prime = [1, 3, 7, 9]

for n in range(N-1): 
  for i in range(len(list[n])):
    for j in start_prime:
      x = list[n][i]*10 + j
      for d in range(2, int(x**0.5)+1):
        if x % d == 0:
          x = 0
          break
      if x != 0:
        list[n+1].append(x)

for i in list[N-1]:
  print(i)